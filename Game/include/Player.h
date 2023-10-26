#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "Game.h"
#include "../../include/SFML/System/Vector2.hpp"

class Player : public Component
{
public:
    Player();

private:
    int health;
    int damage;
    int boostDamage;

    int velocity;
};