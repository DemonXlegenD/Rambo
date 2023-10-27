#pragma once
#include "Scene.h"
#include <SFML/Graphics.hpp>

class SceneGame1 : public Scene
{
public:
	SceneGame1(sf::RenderWindow* window);

	void Awake() override;
	void createPlayer(sf::Texture* texture);
	void Update(sf::Time _delta) override;
	//void Render(sf::RenderWindow* _window) override; 


	//~SceneGame1();

private:
	GameObject* platforme = nullptr;
	GameObject* player = nullptr;
	sf::Texture* texture;
};

