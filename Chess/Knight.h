#include "Piece.h"
#include "Cell.h"

#pragma once
class Knight : public Piece
{
public:
    Knight(bool _isWhite) : Piece(_isWhite) {}

    bool canMove(Cell *(*boardCell)[8], Cell *start, Cell *end) override
    {
        return false;
    }
};
