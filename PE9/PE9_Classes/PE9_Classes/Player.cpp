#include "Player.h"
#include <iostream>

using namespace std;

Player::Player()
{
	name = new char[8] {"Unknown"};
	strength = 10;
	stamina = 10;
	luck = 10;
}

Player::Player(char* name, int strength, int stamina, int luck)
{
	this->name = name;
	this->strength = strength;
	this->stamina = stamina;
	this->luck = luck;
}

void Player::printPlayer()
{
	cout << name << "'s Stats: " << endl;
	cout << "Strength: " << strength << endl;
	cout << "Stamina: " << stamina << endl;
	cout << "Luck: " << luck << endl;
	cout << endl;
}

Player::~Player() {
	// Doesn't work as intended, it creates an error? Not sure why.
	// delete[] name;
}
