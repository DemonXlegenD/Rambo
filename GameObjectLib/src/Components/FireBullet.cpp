#include "Components/FireBullet.h"

//TODO : demander au PROF comment réparer la multiplication car elle ne marche pas
void FireBullet::Update(sf::Time _delta)
{
	if (dirBullet == DirectionBullet::Left)
	{
		GetOwner()->SetPosition(GetOwner()->GetPosition() + Maths::Vector2f::Left + Maths::Vector2f(-10, 0));
	}
	else
	{
		GetOwner()->SetPosition(GetOwner()->GetPosition() + Maths::Vector2f::Right + Maths::Vector2f(10, 0));

	}

}

void FireBullet::setDirection(DirectionBullet newDir) {
	dirBullet = newDir;
}