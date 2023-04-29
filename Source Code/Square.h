#include "Knight.h"
#include "Queen.h"

class Square
{
private:
    Piece *piece;

public:
    Square();
    ~Square();
    void setSquare(Piece *piece);
    Piece *getSquare();
};

Square::Square()
{
    this->piece = nullptr;
}

void Square::setSquare(Piece *piece)
{
    this->piece = piece;
}

Piece *Square::getSquare()
{
    return piece;
}

Square::~Square()
{
    delete[] piece;
}