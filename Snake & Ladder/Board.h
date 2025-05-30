#include <unordered_map>
#include "Snake.h"
#include "Ladder.h"
#include "Jumper.h"

using namespace std;
class Board
{
private:
    int boardLength;

public:
    unordered_map<int, Snake *> snakeHashMap;
    unordered_map<int, Ladder *> ladderHashMap;

    Board(int _boardLength)
    {
        boardLength = _boardLength;
    }

    void addSnakeInBoard(int startPosition, int endPosition)
    {
        Snake *snake = new Snake(startPosition, endPosition);
        snakeHashMap[startPosition] = snake;
    }

    void addLadderInBoard(int startPosition, int endPosition)
    {
        Ladder *ladder = new Ladder(startPosition, endPosition);
        ladderHashMap[startPosition] = ladder;
    }

    int size()
    {
        return boardLength;
    }
};
