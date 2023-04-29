#include "Piece.h"

class Queen : public Piece
{
public:
    Queen(int color, TypePiece type);
    ~Queen();
    vector<Point> canMove(Piece* board[8][8], Point start);
};

Queen::Queen(int color, TypePiece type) : Piece(color, type)
{
}

Queen::~Queen()
{
}

vector<Point> Queen::canMove(Piece* board[8][8], Point start)
{
    vector<Point> listValidMoves;
    Point step;
    int horizontalStepX[4] = {0, 0, 1, -1};
    int horizontalStepY[4] = {1, -1, 0, 0};

    for (int i = 0; i < 4; i++)
    {
        step.x = start.x + horizontalStepX[i];
        step.y = start.y + horizontalStepY[i];
        while (step.x >= 0 && step.x < 8 && step.y >= 0 && step.y < 8)
        {
            if(board[step.x][step.y] != nullptr)
            {
                if(board[step.x][step.y]->getColor() == board[start.x][start.y]->getColor())
                    break;
                else
                {
                    listValidMoves.push_back(step);
                    break;
                }
            }
            listValidMoves.push_back(step);
            step.x += horizontalStepX[i];
            step.y += horizontalStepY[i];
        }
    }
    step.x = 0;
    step.y = 0;

    int diagonalStepX[4] = {1, 1, -1, -1};
    int diagonalStepY[4] = {1, -1, 1, -1};

    for (int i = 0; i < 4; i++)
    {
        step.x = start.x + diagonalStepX[i];
        step.y = start.y + diagonalStepY[i];
        while (step.x >= 0 && step.x < 8 && step.y >= 0 && step.y < 8)
        {
            if(board[step.x][step.y] != nullptr)
            {
                if(board[step.x][step.y]->getColor() == board[start.x][start.y]->getColor())
                    break;
                else
                {
                    listValidMoves.push_back(step);
                    break;
                }
            }
            listValidMoves.push_back(step);
            step.x += diagonalStepX[i];
            step.y += diagonalStepY[i];
        }
    }
    return listValidMoves;
}