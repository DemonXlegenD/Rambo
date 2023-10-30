#pragma once
#include "Scene.h"

class FireBullet : public Component
{
public:
    FireBullet() = default;
    void Update(sf::Time _delta) override;
};