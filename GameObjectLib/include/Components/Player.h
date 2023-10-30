#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "Component.h"

class Player : public Component
{
public:
	enum Direction { Left, Right };
	Player();
	void setDirection(Direction direction);
	Direction getDirection() { return direction; }

private:
	int health;
	int damage;
	int boostDamage;
	Direction direction;
};