#include "Queen.h"
#include "Knight.h"

class Board
{
public:
    Piece *board[8][8];
    int turn;
    int win;

public:
    Board();
    void initBoard();
    bool canMoveInBoard(Point start, Point end);
    void Move();
    bool endGame();
    void renderBoard();
    void Play();
    vector<Point> directionMove(Point start);
    void renderDirecionMove(Point start, vector<Point> listValidMove);
    ~Board();
};

void Board::initBoard()
{
    // add more piece of game chess
    // example add Queen and Knight

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            this->board[i][j] = nullptr;
        }
    }

    this->board[0][3] = new Queen(-1, QUEEN);
    this->board[7][3] = new Queen(1, QUEEN);
    

    this->board[0][1] = new Knight(-1, KNIGHT);
    this->board[0][6] = new Knight(-1, KNIGHT);
    this->board[7][1] = new Knight(1, KNIGHT);
    this->board[7][6] = new Knight(1, KNIGHT);
}

Board::Board()
{
    this->initBoard();
    turn = 1; // 0: turn of white
    win = 0;
}

vector<Point> Board::directionMove(Point start)
{
    Piece *pieceStart = board[start.x][start.y];
    vector<Point> listValidMoves;

    if (pieceStart == nullptr)
        return listValidMoves;
    if (pieceStart->getColor() != turn)
        return listValidMoves;

    listValidMoves = pieceStart->canMove(board, start);
    return listValidMoves;
}

void Board::renderDirecionMove(Point start, vector<Point> listValidMove)
{
    int a[8][8];
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            a[i][j] = 0; // ascii 48: 0
        }
    }

    if (board[start.x][start.y] != nullptr)
        a[start.x][start.y] = board[start.x][start.y]->getColor() * board[start.x][start.y]->getType();

    for (int i = 0; i < listValidMove.size(); i++)
    {
        Point temp = listValidMove[i];
        a[temp.x][temp.y] = 9;
    }

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cout << a[i][j] << "  ";
        }
        cout << endl;
    }
}

bool Board::canMoveInBoard(Point start, Point end)
{
    Piece *pieceStart = board[start.x][start.y];

    if (pieceStart == nullptr)
        return false;
    if (pieceStart->getColor() != turn)
        return false;

    vector<Point> listValidMoves = pieceStart->canMove(board, start);
    for (int i = 0; i < listValidMoves.size(); i++)
    {
        if (listValidMoves[i] == end)
            return true;
    }

    return false;
}

void Board::Move()
{
    Point start;
    do
    {
        cout << "Input point start: ";
        cin >> start.x >> start.y;
    } while ((start.x > 7 || start.x < 0) || (start.y > 7 || start.y < 0));

    cout << endl
         << "Direction move of Piece you choose" << endl;
    renderDirecionMove(start, directionMove(start));
    cout << endl;

    Point end;
    do
    {
        cout << "Input point end: ";
        cin >> end.x >> end.y;
    } while ((end.x > 7 || end.x < 0) || (end.y > 7 || end.y < 0));

    if (canMoveInBoard(start, end))
    {
        delete board[end.x][end.y];
        board[end.x][end.y] = board[start.x][start.y];
        board[start.x][start.y] = nullptr;

        if (turn == 1)
            turn = -1;
        else if (turn == -1)
            turn = 1;
    }
}

bool Board::endGame()
{
    int cntPieceBlack = 0;
    int cntPieceWhite = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (board[i][j] != nullptr)
            {
                if (board[i][j]->getColor() * board[i][j]->getType() < 0)
                    cntPieceBlack++;
                else if (board[i][j]->getColor() * board[i][j]->getType() > 0)
                    cntPieceWhite++;
            }
        }
    }

    if (cntPieceBlack != 0 && cntPieceWhite == 0)
    {
        win = -1;
        return true;
    }
    else if (cntPieceBlack == 0 && cntPieceWhite != 0)
    {
        win = 1;
        return true;
    }

    return false;
}

void Board::renderBoard()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (board[i][j] != nullptr)
            {
                cout << board[i][j]->getColor() * board[i][j]->getType() << "   ";
            }
            else
                cout << "0   ";
        }
        cout << endl;
    }
}

void Board::Play()
{
    while (!endGame())
    {
        cout << "Turn: " << turn << endl;
        renderBoard();
        Move();
    }
    if (win == 1)
        cout << "White win " << endl;
    else if (win == -1)
        cout << "Black win " << endl;
}

Board::~Board()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            delete board[i][j];
        }
    }
}
