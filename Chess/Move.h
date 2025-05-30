#include "Cell.h"
#pragma once
class Move
{
private:
    Cell *startBlock;
    Cell *endBlock;

public:
    Move(Cell *startBlock, Cell *endBlock)
    {
        endBlock = endBlock;
        startBlock = startBlock;
    }

    bool isValid()
    {
        return !(startBlock->getPiece()->isWhite() == endBlock->getPiece()->isWhite());
    }

    Cell *getStartBlock()
    {
        return startBlock;
    }

    Cell *getEndBlock()
    {
        return endBlock;
    }
};