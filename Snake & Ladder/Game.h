#pragma once
#include "iostream"
#include "queue"
#include "Board.h"
#include "Player.h"
#include "Dice.h"

using namespace std;

class Game
{
private:
    queue<Player *> playerTurn;
    queue<Player *> winner;
    Board *board;
    Dice *dice;

public:
    ~Game()
    {
        delete board;
        delete dice;
        while (!playerTurn.empty())
        {
            delete playerTurn.front();
            playerTurn.pop();
        }
    }
    void showWinners()
    {
        int i = 1;
        cout << "****" << endl;
        while (!winner.empty())
        {
            cout << winner.front()->getPlayerName() << "Rank : " << i << endl;
            i++;
            winner.pop();
        }
        cout << "****" << endl;
    }
    void start()
    {
        while (playerTurn.size() > 1)
        {
            Player *player = playerTurn.front();
            playerTurn.pop();
            int nextPosition = player->getCurrentPosition();
            int rollDice = dice->rollDice();

            nextPosition += rollDice;

            if (nextPosition > board->size())
            {
                cout << "Can't Reach End" << player->getPlayerName() << endl;
                playerTurn.push(player);
                continue;
            }

            if (nextPosition == board->size())
            {
                winner.push(player);
            }
            else
            {
                if (board->snakeHashMap.find(nextPosition) != board->snakeHashMap.end())
                {
                    cout << "Snake is present at *** " << nextPosition << " *** " << endl;
                    nextPosition = board->snakeHashMap[nextPosition]->jump(nextPosition);
                    player->setCurrentPosition(nextPosition);
                    playerTurn.push(player);
                }
                else if (board->ladderHashMap.find(nextPosition) != board->ladderHashMap.end())
                {
                    cout << "Ladder is present at *** " << nextPosition << " *** " << endl;
                    nextPosition = board->ladderHashMap[nextPosition]->jump(nextPosition);
                    player->setCurrentPosition(nextPosition);
                    playerTurn.push(player);
                }
                else
                {
                    player->setCurrentPosition(nextPosition);
                    playerTurn.push(player);
                }

                cout << player->getPlayerName() << " Moved to " << player->getCurrentPosition() << endl;
            }
        }

        winner.push(playerTurn.front());
        playerTurn.pop();
    }

    void initialize()
    {
        int boardLength;
        cout << "Enter Board Size: ";
        cin >> boardLength;

        board = new Board(boardLength);

        int numberOfSnake = 0;
        cout << endl
             << "Number of Snakes in Game: ";
        cin >> numberOfSnake;

        for (int i = 0; i < numberOfSnake; i++)
        {
            int startPosition = 0, endPosition = 0;
            cout << "Enter Snake " << i + 1 << " Position " << endl;
            cout << "Snake Head at:";
            cin >> startPosition;
            cout << "Snake Tail at:";
            cin >> endPosition;

            if (startPosition >= 1 && endPosition >= 0 &&
                startPosition < boardLength && endPosition < boardLength &&
                startPosition > endPosition)
            {
                board->addSnakeInBoard(startPosition, endPosition);
            }
            else
            {
                cout << "Enter Valid Position of the Snake!!!" << endl;
                i--;
            }
        }

        int numberOfLadders = 0;
        cout << "Number of Ladders in Game: ";
        cin >> numberOfLadders;

        for (int i = 0; i < numberOfLadders; i++)
        {
            int startPosition = 0, endPosition = 0;
            cout << "Enter Ladder " << i + 1 << " Position" << endl;

            cout << "Ladder Start at:";
            cin >> startPosition;
            cout << "Ladder end at:";
            cin >> endPosition;

            if (startPosition >= 0 && endPosition >= 0 &&
                startPosition < boardLength && endPosition < boardLength &&
                startPosition < endPosition)
            {
                board->addLadderInBoard(startPosition, endPosition);
            }
            else
            {
                cout << "Enter Valid Position of the Ladder!!!" << endl;
                i--;
            }
        }

        int numberOfPlayers = 0;
        cout << "Enter Number of Playes: ";
        cin >> numberOfPlayers;

        for (int i = 0; i < numberOfPlayers; i++)
        {
            string name;
            cout << "Enter Player " << i + 1 << " Name: ";
            cin >> name;

            Player *player = new Player(name);
            playerTurn.push(player);
        }

        int numberOfDice = 1;
        cout << "Enter Number of Dice you would like to use: ";
        cin >> numberOfDice;
        dice = new Dice(numberOfDice);
    }
};
