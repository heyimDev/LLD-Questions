#include "Cell.h"
#include "Pawn.h"
#include "Queen.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "King.h"
#include <array>
#pragma once
using namespace std;

class Board
{
private:
    Cell *board[8][8];

public:
    void initializeBoard()
    {
        board[0][0] = new Cell({0, 0}, new Rook(true), "Rook");
        board[0][1] = new Cell({0, 1}, new Knight(true), "Knight");
        board[0][2] = new Cell({0, 2}, new Bishop(true), "Bishop");
        board[0][3] = new Cell({0, 3}, new Queen(true), "Queen");
        board[0][4] = new Cell({0, 4}, new King(true), "King");
        board[0][5] = new Cell({0, 5}, new Bishop(true), "Bishop");
        board[0][6] = new Cell({0, 6}, new Knight(true), "Knight");
        board[0][7] = new Cell({0, 7}, new Rook(true), "Rook");

        for (int i = 0; i < 8; i++)
        {
            board[1][i] = new Cell({1, i}, new Pawn(true), "Pawn");
        }

        for (int i = 2; i < 6; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                board[i][j] = new Cell({i, j}, nullptr, "");
            }
        }

        for (int i = 0; i < 8; i++)
        {
            board[6][i] = new Cell({6, i}, new Pawn(false), "Pawn");
        }

        board[7][0] = new Cell({7, 0}, new Rook(false), "Rook");
        board[7][1] = new Cell({7, 1}, new Knight(false), "Knight");
        board[7][2] = new Cell({7, 2}, new Bishop(false), "Bishop");
        board[7][3] = new Cell({7, 3}, new Queen(false), "Queen");
        board[7][4] = new Cell({7, 4}, new King(false), "King");
        board[7][5] = new Cell({7, 5}, new Bishop(false), "Bishop");
        board[7][6] = new Cell({7, 6}, new Knight(false), "Knight");
        board[7][7] = new Cell({7, 7}, new Rook(false), "Rook");
    }

    Board()
    {
        initializeBoard();
    }

    Cell *(*getConfiguredBoard())[8]
    {
        return board;
    }
};