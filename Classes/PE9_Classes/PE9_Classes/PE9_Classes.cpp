#include <iostream>
#include "Player.h"

using namespace std;

int main()
{
	// On stack, using default constructor
	Player firstPlayer = Player();

	// On stack, using parameterized constructor
	char omar[5] = "Omar";
	Player secondPlayer = Player(omar, 2, 3, 4);

	// On heap, using default constructor
	Player* thirdPlayer = new Player();

	// On heap, using parameterized constructor
	char notOmar[8] = "notOmar";
	Player* fourthPlayer = new Player(notOmar, 4, 3, 2);

	// Printing Time >:D
	firstPlayer.printPlayer();
	secondPlayer.printPlayer();
	thirdPlayer->printPlayer();
	fourthPlayer->printPlayer();

	// Memmory Management
	delete thirdPlayer;
	delete fourthPlayer;
}