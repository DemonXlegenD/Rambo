#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"

class Player
{
public:
    Player();

protected:
    int health;
    int damage;
    int boostDamage;

};