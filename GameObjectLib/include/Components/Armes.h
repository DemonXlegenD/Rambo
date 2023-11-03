#pragma once
#include <Components/Component.h>

class Armes : public Component
{
public :
	Armes();
	~Armes();


	void Update(sf::Time _delta) override;
	void Shoot();
private :
	float fireRate = 1.f;
	float fireCooldown = 0.f;
	int mag = 10;
	int maxAmo = 10;
	float reload = 1.f;
	float activeReload = 0.f;
};

