#include <iostream>
#include <random>

using namespace std;
class Dice
{
private:
    int totalDiceInGame;
    random_device rd;
    mt19937 gen;
    uniform_int_distribution<> range;

public:
    Dice(int _totalDiceInGame) : gen(rd()), range(1, 6)
    {
        totalDiceInGame = _totalDiceInGame;
        if (_totalDiceInGame <= 0)
        {
            cout << "Invalid number of dice: " << _totalDiceInGame << ". Defaulting to 1." << endl;
            totalDiceInGame = 1;
        }
        else
        {
            totalDiceInGame = _totalDiceInGame;
        }
    }

    int rollDice()
    {
        int total = 0;
        for (int i = 0; i < totalDiceInGame; ++i)
        {
            total += range(gen);
        }
        return total;
    }
};