#include "Jumper.h"

class Snake : public Jumper
{
public:
    Snake(int startPosition, int endPosition) : Jumper(startPosition, endPosition) {}

    int jump(int currentPosition) override
    {
        if (currentPosition == startPosition)
        {
            return endPosition;
        }

        return currentPosition;
    }
};
