
#include "Components/Entities/Player.h"


Player::Player() : Entity(200, 30, 20.f)
{
    directionPlayer = false;
	direction = Direction::Right;
}

Player::Player(int _hp, int _damage, float _speed) : Entity(_hp, _damage, _speed)
{
    directionPlayer = false;
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