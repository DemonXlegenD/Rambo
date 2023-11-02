#pragma once
#include <Components/Component.h>

class Armes : public Component
{
public :
	Armes(float fireRate = 1.f, int magazine = 10);
	~Armes();
	void Update(sf::Time _delta) override;
	void Shoot();
private :
	float fireRate = 1.f;
	float fireCooldown = 0;
	int mag = 10;
	int maxAmo = 10;
	float reload = 1.f;
	float activeReload = 0.f;
};

