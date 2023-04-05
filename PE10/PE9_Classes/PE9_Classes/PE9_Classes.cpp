#include <iostream>
#include "Player.h"
#include "Fighter.h"

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
	cout << endl;
	secondPlayer.printPlayer();
	cout << endl;
	thirdPlayer->printPlayer();
	cout << endl;
	fourthPlayer->printPlayer();
	cout << endl;

	// Memmory Management
	delete thirdPlayer;
	delete fourthPlayer;

	// PE 10
	// 2 fighters
	Fighter defFighter = Fighter();

	char ramo[5] = "Ramo";
	Fighter parmFighter = Fighter(ramo, 4, 3, 2, 99);

	defFighter.PrintFighters();
	cout << endl;
	parmFighter.PrintFighters();

}