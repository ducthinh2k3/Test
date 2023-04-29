#pragma once
#include <iostream>
#include <vector>
#include "Point.h"
using namespace std;

enum TypePiece
{
    ROOK = 1,
    KNIGHT = 2,
    BISHOP = 3,
    QUEEN = 4,
    KING = 5,
    PAWN = 6
};

class Piece
{
private:
    int color; // 1: white, -1: black
    TypePiece type;

public:
    Piece(int color, TypePiece type);
    virtual ~Piece();
    virtual vector<Point> canMove(Piece *board[8][8], Point start) = 0;
    int getColor();
    TypePiece getType();
};

int Piece::getColor()
{
    return this->color;
}

Piece::Piece(int color, TypePiece type)
{
    this->color = color;
    this->type = type;
}

TypePiece Piece::getType()
{
    return this->type;
}

Piece::~Piece()
{
}
