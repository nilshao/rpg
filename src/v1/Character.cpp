#include "InGame.h"

Character::Character()
{
	this->name = "";
	this->LV = 1;

	this->HP = 100;
	this->maxHP = 100;

	this->MP = 40;
	this->maxMP = 40;
	this->vitality = 5;
}
Character::~Character()
{
}
void Character::CharacterLoading(const string name, const int LV,
								 const int HP, const int maxHP,
								 const int MP, const int maxMP, int vitality)
{
	this->name = name;

	this->LV = LV;
	this->HP = maxHP;
	this->maxHP = maxHP;
	this->MP = MP;
	this->maxMP = maxMP;
	this->vitality = vitality;
	// this->updateStats();
}

void Character::initialize(const string name)
{
	this->name = name;
	this->LV = 1;
	this->HP = 100;
	this->maxHP = 100;
	this->MP = 40;
	this->maxMP = 40;
	this->vitality = 5;
}
void Character::ShowStats()
{
	cout << "Your current state shows below" << endl;
	// TODO: ADD character info;
	cout << "Your current character is " << this->name << endl;
	cout << "Your current HP is " << this->HP << endl;
	cout << "Your current MP is " << this->MP << endl;
}
void Character::takeDamage(const int damage)
{
	this->HP -= damage;

	if (this->HP <= 0)
	{
		this->HP = 0;
	}
}
bool Character::characterstate()
{
	return this->HP > 0 ?: false;
}
string Character::AttributeToString()
{
	return name + " " + to_string(LV) + " " +
		   to_string(HP) + " " + to_string(maxHP) + " " +
		   to_string(MP) + " " + to_string(maxMP) + " " +
		   to_string(vitality);
}