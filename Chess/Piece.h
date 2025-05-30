#pragma once
#include "Cell.h"

class Cell;

class Piece
{
private:
    bool _isWhite;
    bool _killed;

public:
    Piece(bool isWhite)
    {
        _isWhite = isWhite;
        _killed = false;
    }

    bool isWhite()
    {
        return _isWhite;
    }

    bool isKilled()
    {
        return _killed;
    }

    void setKilled()
    {
        _killed = true;
    }

    virtual bool canMove(Cell *(*boardCell)[8], Cell *start, Cell *end) {};
};