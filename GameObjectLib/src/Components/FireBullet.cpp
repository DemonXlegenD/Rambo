#include "Components/FireBullet.h"
#include "Components/Armes.h"
#include "SceneManager.h"
#include "Components/SquareCollider.h"

FireBullet::FireBullet() {
	this->player = nullptr;
}
//TODO : demander au PROF comment réparer la multiplication car elle ne marche pas
void FireBullet::Update(sf::Time _delta)
{
	Component::Update(_delta);

	if (dirBullet == DirectionBullet::Left)
	{
		GetOwner()->SetPosition(GetOwner()->GetPosition() + Maths::Vector2f::Left * 500.0f * _delta.asSeconds());
	}
	else
	{
		GetOwner()->SetPosition(GetOwner()->GetPosition() + Maths::Vector2f::Right * 500.0f * _delta.asSeconds());
	}

	if (GetOwner()->GetPosition().GetX() > SceneManager::GetWindowWidth()
		|| GetOwner()->GetPosition().GetY() > SceneManager::GetWindowHeight()
		|| GetOwner()->GetPosition().GetY() < 0
		|| GetOwner()->GetPosition().GetX() < 0
		)
	{
		this->player->GetComponent<Armes>()->RemoveBullet(GetOwner());
		SceneManager::GetActiveScene()->RemoveGameObject(GetOwner());
	}
	isColliding();
}

void FireBullet::setDirection(GameObject* _player) {
	this->player = _player;
	if (this->player->GetComponent<Player>()->getDirection() == Player::Direction::Right) {
		this->dirBullet = FireBullet::DirectionBullet::Right;
	}
	else {
		this->dirBullet = FireBullet::DirectionBullet::Left;
	}
	GetOwner()->SetPosition(GetOwner()->GetPosition() + Maths::Vector2f::Right * 6.0f);
}

void FireBullet::isColliding()
{
	
	bool colliding = false;
	Armes* arme = GetOwner()->GetComponent<Armes>();
	
	for(size_t i = 0; i < arme->GetBullets().size(); i++ )
	{
		std::cout << "carre";
		for (size_t j = 0; j < SceneManager::GetActiveGameScene()->GetEnemies().size(); j++ ) {
			if (SquareCollider::IsColliding(*(SceneManager::GetActiveGameScene()->GetEnemie(j)->GetComponent<SquareCollider>()), *(arme->GetBullet(i)->GetComponent<SquareCollider>()))) {
				colliding = true;
				std::cout << "c'est bon";
				break;
			}
		}
	}
	
}