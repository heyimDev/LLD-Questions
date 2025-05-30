#pragma once
#include "Piece.h"
#include "Cell.h"

class Bishop : public Piece
{
public:
    Bishop(bool _isWhite) : Piece(_isWhite) {}

    bool canMove(Cell *(*boardCell)[8], Cell *start, Cell *end) override
    {
        return false;
    }
};
