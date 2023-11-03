#pragma once

#include "Components/SpriteRenderer.h"
#include "Scene.h"

class FireBullet : public Component
{
public:
	enum DirectionBullet { Left, Right };
	DirectionBullet dirBullet = DirectionBullet::Right;
	FireBullet() = default;
	void setDirection(GameObject* _player);
	void Update(sf::Time _delta) override;

};