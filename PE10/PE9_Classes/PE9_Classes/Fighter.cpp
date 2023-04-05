#include "Fighter.h"
#include <iostream>

using namespace std;

Fighter::Fighter() : Player(new char[8] {"Unknown"}, 0,0,0)
{
	this->weaponSkill = weaponSkill;
}

Fighter::Fighter(char* name, int strength, int stamina, int luck, int weaponSkill) 
	: Player(name, strength, stamina, luck)
{
	this->weaponSkill = weaponSkill;
}

void Fighter::PrintFighters()
{
	Player::printPlayer();
	cout << "WeaponSkill: " << weaponSkill << endl;
}
