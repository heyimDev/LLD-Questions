#include <iostream>
#include "game.h"

using namespace std;

int main()
{
    Game *game = new Game();

    cout << "Lets Start The Game" << endl;
    game->initialize();
    game->start();
    game->showWinners();
    return 1;
}