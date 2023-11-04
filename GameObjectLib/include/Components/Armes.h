#pragma once
#include <Components/Component.h>

class Armes : public Component
{
public :
	Armes();
	~Armes();


	void Update(sf::Time _delta) override;
	void Render(sf::RenderWindow* _window) override;
	void Shoot();
	void RemoveBullet(GameObject* _objectToRemove) {
		bullets.erase(std::remove_if(bullets.begin(), bullets.end(),
			[_objectToRemove](GameObject* obj) {
				return obj == _objectToRemove;
			}), bullets.end());
	}

	std::vector<GameObject*> GetBullets() { return bullets; }
	GameObject* GetBullet(int _index) { return bullets[_index];}
private :
	float fireRate = 1.f;
	float fireCooldown = 0.f;
	int mag = 10;
	int maxAmo = 10;
	float reload = 1.f;
	float activeReload = 0.f;
	sf::Texture* texture;
	std::vector<GameObject*> bullets;
};

