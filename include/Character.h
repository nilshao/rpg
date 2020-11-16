#include <iostream>
#include <fstream>
#include <pthread.h>
#include <math.h>
#include <sstream>
#include <string>
#include <stdlib.h>


using namespace std;

class Character
{
private:
    string name;
    int LV;
    int HP;
    int maxHP;
    int MP;
    int maxMP;
    int vitality;

public:
    Character();

    virtual ~Character();

    //Functions
    void CharacterLoading(string name, int LV, int HP, int maxHP, int MP, int maxMP, int vitality);
    void initialize(const string name);
    void takeDamage(const int damage);
    void ShowStats();
    bool characterstate();
    string AttributeToString();
};