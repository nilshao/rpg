# include <iostream>
# include <fstream>
# include <pthread.h>
# include <math.h>

using namespace std;

class Character
{
    Character();
    virtual ~Character();
    Character(string name, int LV, int HP, int maxHP, int MP, int maxMP, int vitality)
    AttributeToString();
}