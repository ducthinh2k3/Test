#include "Piece.h"

class Knight : public Piece
{
public:
    Knight(int color, TypePiece type);
    ~Knight();
    vector<Point> canMove(Piece *board[8][8], Point start);
};

Knight::Knight(int color, TypePiece type) : Piece(color, type)
{
}

Knight::~Knight()
{
}

vector<Point> Knight::canMove(Piece *board[8][8], Point start)
{
    vector<Point> listValidMoves;
    Point step;
    int x[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int y[8] = {1, 2, 2, 1, -1, -2, -2, -1};

    for (int i = 0; i < 8; i++)
    {
        step.x = start.x + x[i];
        step.y = start.y + y[i];

        // check Point out of board
        if (step.x >= 0 && step.y >= 0 && step.x < 8 && step.y < 8)
            listValidMoves.push_back(step);
    }

    for (int i = 0; i < listValidMoves.size(); i++)
    {
        Point temp;
        temp.x = listValidMoves[i].x;
        temp.y = listValidMoves[i].y;
        if (board[temp.x][temp.y] != nullptr)
        {
            if (board[temp.x][temp.y]->getColor() == board[start.x][start.y]->getColor())
            {
                listValidMoves.erase(listValidMoves.begin() + i);
                i--;
            }
        }
    }

    return listValidMoves;
}