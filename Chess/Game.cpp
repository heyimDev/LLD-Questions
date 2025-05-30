#include "Board.h"
#include "Player.h"
#include "Move.h"

class Cell;

class Game
{
private:
    Board *board;
    Player *player1, *player2;
    bool isWhiteTurn;
    string status;
    Cell *(*boardCell)[8];

public:
    Game()
    {
        player1 = new Player("first player");
        player2 = new Player("second player");
        board = new Board();
        boardCell = board->getConfiguredBoard();
        isWhiteTurn = true;
        status = "active";
    }

    void makeMove(Move *move, Player *player)
    {
         cout<<"Hellod";
        cout << move->isValid();
       
        if (move->isValid())
        {
            Piece *sourcePiece = move->getStartBlock()->getPiece();

            if (sourcePiece->canMove(boardCell, move->getStartBlock(), move->getEndBlock()))
            {
                cout<<"Shivam chutiya";
                Piece *destinationPiece = move->getEndBlock()->getPiece();

                if (destinationPiece != nullptr)
                {
                    // Check for win condition
                    if (dynamic_cast<King *>(destinationPiece) != nullptr && isWhiteTurn)
                    {
                        cout << "white Win" << endl;
                        status = "Won";
                        return;
                    }

                    if (dynamic_cast<King *>(destinationPiece) != nullptr && !isWhiteTurn)
                    {
                        cout << "Black Win" << endl;
                        status = "Won";
                        return;
                    }

                    destinationPiece->setKilled();
                }
                cout <<"me noob";
                // Execute the move
                move->getEndBlock()->setPiece(sourcePiece);
                move->getStartBlock()->setPiece(nullptr);

                // Toggle turn
                isWhiteTurn = !isWhiteTurn;
            }
        }
    }

    void start()
    {
        while (status == "active")
        {
            pair<int, int> startPosition, endPosition;
            cout << "Enter Move Start Position";
            cin >> startPosition.first >> startPosition.second;
            cout << "Enter Move End Position";
            cin >> endPosition.first >> endPosition.second;
            cout << isWhiteTurn <<" say aaah";
            if (isWhiteTurn)
            {
                this->makeMove(new Move(boardCell[startPosition.first][startPosition.second], boardCell[endPosition.first][endPosition.second]), player1);
            }
            else
            {
                this->makeMove(new Move(boardCell[startPosition.first][startPosition.second], boardCell[endPosition.first][endPosition.second]), player2);
            }
        }
    }
};

int main()
{
    Game *game = new Game();
    game->start();
    return 1;
}