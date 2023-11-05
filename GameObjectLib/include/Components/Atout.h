#pragma once
#include "Component.h"
#include "Scene.h"
#include "SceneManager.h"

class Atout : public Component
{
public:
	Atout();
	void CreateButtonAdd();

	//void Create() override;
	void Render(sf::RenderWindow* _window) override;
	void Update(sf::Time _delta) override;
	


private:

	std::vector<GameObject*> atouts;

	GameObject* addSpeed = nullptr;
	GameObject* addDamamge = nullptr;
	GameObject* addHealt = nullptr;

	bool speed;
	bool damage;
	bool health;
};

