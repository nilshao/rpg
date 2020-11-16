#include <iostream>
#include <fstream>
#include <pthread.h>
#include <math.h>
#include <cassert>
#include <Character.h>
#include <stdlib.h>

using namespace std;

class InGame
{

private:
    int option;
    Character character;
    string fileName;

public:
    InGame();
    virtual ~InGame();

    //Functions
    void init_Game();
    void createGame();
    void InGame_Menu();
    void Fight();
    void ShowStats();
    void saveGame();
    void loadGame();
    void newGame();
    void Exit();
    bool game_status();
};