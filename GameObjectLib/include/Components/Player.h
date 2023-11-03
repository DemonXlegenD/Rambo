#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "Component.h"

class Player : public Component
{
public:
	enum Direction { Left, Right };
	Player();
	void Update(sf::Time _delta);
	void setDirection(Direction direction);
	Direction getDirection() { return direction; }

public:
	int health;
	int damage;
	int boostDamage;
	Direction direction;
	bool directionPlayer;
};