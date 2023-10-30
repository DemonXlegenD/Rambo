#include "Components/Player.h"


Player::Player()
{
	this->health = 200;
	this->damage = 10;
	this->boostDamage = 1;
}

void Player::setDirection(Direction newDirection) {
	direction = newDirection;
}