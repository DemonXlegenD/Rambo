#include "Components/FireBullet.h"


void FireBullet::Update(sf::Time _delta)
{
    GetOwner()->SetPosition(GetOwner()->GetPosition() + Maths::Vector2f::Right);
}