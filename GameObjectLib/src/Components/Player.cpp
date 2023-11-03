
#include "Components/Player.h"


Player::Player()
{
	this->health = 200;
	this->damage = 10;
	this->boostDamage = 1;
	direction = Direction::Right;
}

void Player::setDirection(Direction newDirection) {
	direction = newDirection;
}

void Player::Update(sf::Time _delta)
{
    if (direction == Direction::Left)
    {
        directionPlayer = true;
    }
    else if (direction == Direction::Right)
    {
        directionPlayer = false;
    }
}