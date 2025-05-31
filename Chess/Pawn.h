#include "Piece.h"
#include "Cell.h"
#pragma once
class Pawn : public Piece
{
public:
    Pawn(bool _isWhite) : Piece(_isWhite) {}

    bool canMove(Cell *(*boardCell)[8], Cell *start, Cell *end) override
    {
        cout<<"ismoving";
        pair<int, int> startingLocation = start->getLocation();
        pair<int, int> endingLocation = end->getLocation();

        if (end->getPiece() != nullptr)
        {
            if (
                startingLocation.first + 1 == endingLocation.first && startingLocation.second + 1 >= 0 && startingLocation.second + 1 < 8 && startingLocation.second + 1 == endingLocation.second ||
                startingLocation.first + 1 == endingLocation.first && startingLocation.second - 1 >= 0 &&startingLocation.second - 1 < 8 && startingLocation.second - 1 == endingLocation.second)
            {
                return true;
            }
        }

        if (startingLocation.first + 1 == endingLocation.first && startingLocation.second == endingLocation.second)
            return true;

        return false;
    }
};
