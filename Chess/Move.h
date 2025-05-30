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
        this->endBlock = endBlock;
        this->startBlock = startBlock;
    }

    bool isValid()
    {
        cout<<"hey";
        cout << startBlock->getLocation().first << " " << startBlock->getLocation().first <<" "  << endBlock->getLocation().first << " " <<endBlock->getLocation().second; 
        
        return (endBlock->getPiece() == nullptr)|| !((startBlock->getPiece()->isWhite()== endBlock->getPiece()->isWhite()));
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