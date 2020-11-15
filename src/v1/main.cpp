#include <iostream>
#include <fstream>
#include <pthread.h>
#include <math.h>
#include "InGame.h"

int main()
{
    InGame game;
    game.initGame();

    while (game.gameStatus)
    {
        game.Menu();
    }
    return 0;
}
