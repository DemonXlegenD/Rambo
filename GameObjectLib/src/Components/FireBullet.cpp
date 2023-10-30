#include "Components/FireBullet.h"

//TODO : demander au PROF comment réparer la multiplication car elle ne marche pas
void FireBullet::Update(sf::Time _delta)
{
    GetOwner()->SetPosition(GetOwner()->GetPosition() + Maths::Vector2f::Right * 6.0f);
}