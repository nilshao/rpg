# include <iostream>
# include <fstream>
# include <pthread.h>
# include <math.h>

# include <Character.h>

using namespace std;

class InGame{

private:
    int option;
    Character character;

public:
    InGame();
    virtual ~InGame();

    //Functions
    void init_Game()
    void Menu();
    void Fight();
    void ShowStates();
    void saveGame();
    void loadGame();
    void newGame();
    void Exit();
};
