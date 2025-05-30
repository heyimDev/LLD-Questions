#include <string>

using namespace std;

class Player
{
private:
    int currentPosition;
    string name;

public:
    Player(string _name)
    {
        currentPosition = 0;
        name = _name;
    }

    string getPlayerName()
    {
        return name;
    }

    void setCurrentPosition(int _currentPosition)
    {
        currentPosition = _currentPosition;
    }

    int getCurrentPosition()
    {
        return currentPosition;
    }
};