#include <iostream>
#include <fstream>
#include <pthread.h>
#include <math.h>
#include "InGame.h"

int main()
{
    system("clear");
    InGame game;
    game.init_Game();
    
    while (game.game_status())
    {
        game.InGame_Menu();
    }

    return 0;
}
