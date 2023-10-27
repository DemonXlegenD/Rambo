#pragma once
#include "Scene.h"
#include "Components/SpriteBullet.h"

class FireBullet : public Component
{
public:
    FireBullet() = default;
    void Update(sf::Time _delta) override;
};