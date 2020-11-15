#include "Character.h"

Character::Character(){
	this->name = "";
	this->LV = 1;

	this->HP = 100;
	this->maxHP = 100;

	this->MP = 40;
	this->maxMP = 40;

}
Character::~Character(){
}

Character::Character(string name, int LV,
					int HP, int maxHP,
					int MP, int maxMP, int vitality){
	this->name = name;

	this->LV = LV;

	this->HP = HP;
	this->maxHP = maxHP;
	this->MP = MP;
	this->maxMP = maxMP;

//	this->updateStats();
}

string Character::AttributeToString() const{
	return 	name + " " + to_string(LV) + " " + 
			to_string(HP) + " "	+ to_string(maxHP) + " " + 
			to_string(MP) + " "	+ to_string(maxMP);
}

//void Character::updateStats()