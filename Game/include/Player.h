#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "../GameObjectLib/include/Scene.h"

class Player : public Component
{
public:
    Player();

private:
    int health;
    int damage;
    int boostDamage;
};