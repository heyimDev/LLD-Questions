#include "Jumper.h"

class Ladder : public Jumper
{
public:
    Ladder(int startPosition, int endPosition) : Jumper(startPosition, endPosition) {}

    int jump(int currentPosition) override
    {
        if (currentPosition == startPosition)
        {
            return endPosition;
        }

        return currentPosition;
    }
};