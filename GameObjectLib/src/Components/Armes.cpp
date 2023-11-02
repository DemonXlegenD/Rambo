#include "Components/Armes.h"
#include "GameObject.h"
#include "Components/FireBullet.h"
#include "SceneManager.h"

Armes::Armes(float fireRate, int magazine) : fireRate(fireRate), mag(magazine) {}
Armes::~Armes() {}

void Armes::Update(sf::Time _delta) {
	if (activeReload > 0) {
		activeReload -= _delta.asSeconds();
	}
	else if (activeReload <= 0 && mag <= 0) {
		mag = maxAmo;
	}
	if (fireCooldown > 0) {
		fireCooldown -= _delta.asSeconds();
	}

}

void Armes::Shoot() {
	if (mag > 0 && fireCooldown <= 0) {
		mag -= 1;
		fireCooldown = fireRate;
		sf::Texture* texture = new sf::Texture();
		if (!texture->loadFromFile("../assets/Sprite/player/weaponBullet/weapon_bullet_0.png")) {
			std::cout << "pas d'image" << std::endl;
		}

		GameObject* bullet = SceneManager::GetActiveScene()->CreateBulletGameObject("Bullet", *texture, 2.5f, 2.5f, GetOwner());
		bullet->SetPosition(GetOwner()->GetPosition());
		FireBullet* firing = bullet->CreateComponent<FireBullet>();
		if (GetOwner()->GetComponent<Player>()->getDirection() == Player::Direction::Right) {
			firing->setDirection(FireBullet::DirectionBullet::Right);
		}
		else {
			firing->setDirection(FireBullet::DirectionBullet::Left);
		}
	}
	else {
		if (activeReload <= 0)
		{
			activeReload = reload;
		}
	}
}