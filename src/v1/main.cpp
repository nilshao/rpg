#include <iostream>
#include <fstream>
#include <pthread.h>
#include <math.h>
#include "InGame.h"

int main()
{
    InGame game;
    game.init_Game();

    while (game.game_status())
    {
        game.Menu();
    }

    return 0;
}
