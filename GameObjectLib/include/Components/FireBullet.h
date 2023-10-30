#pragma once

#include "Components/SpriteBullet.h"

class FireBullet : public Component
{
public:
	enum DirectionBullet { Left, Right };
	DirectionBullet dirBullet = DirectionBullet::Right;
	FireBullet() = default;
	void setDirection(DirectionBullet newDir);
	void Update(sf::Time _delta) override;

};