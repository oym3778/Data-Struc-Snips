#pragma once
class Player
{
private:
	char* name;
	int strength;
	int stamina;
	int luck;


public:
	Player();
	Player(char* name, int strength, int stamina, int luck);
	~Player();
	void printPlayer();
};

