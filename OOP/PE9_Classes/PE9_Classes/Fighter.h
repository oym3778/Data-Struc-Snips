#pragma once
#include "Player.h"
class Fighter :
    public Player
{
public:
    int weaponSkill;

    Fighter();
    Fighter(char* name, int strength, int stamina, int luck, int weaponSkill);

    void PrintFighters();

};

