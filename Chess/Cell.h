#pragma once

#include <iostream>
#include "Piece.h"

using namespace std;

class Piece;

class Cell
{
private:
    Piece *piece;
    string label;
    pair<int, int> location;

public:
    Cell(pair<int, int> _location, Piece *_piece, string _label)
    {
        location = _location;
        piece = _piece;
        label = _label;
    }

    pair<int, int> getLocation()
    {
        return location;
    }

    Piece *getPiece()
    {
        return piece;
    }

    void setPiece(Piece *_piece)
    {
        piece = _piece;
    }
};
