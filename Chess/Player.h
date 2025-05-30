#include <string>
using namespace std;
#pragma once
class Player
{
private:
    string name;

public:
    Player(string _name)
    {
        name = _name;
    }

    string getPlayerName()
    {
        return name;
    }
};