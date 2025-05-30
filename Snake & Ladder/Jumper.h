#pragma once

class Jumper
{
protected:
    int startPosition;
    int endPosition;

public:
    Jumper(int _startPosition, int _endPosition)
    {
        endPosition = _endPosition;
        startPosition = _startPosition;
    }

    virtual int jump(int currentPosition) = 0;
};