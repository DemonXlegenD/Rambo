#pragma once
#include "Scene.h"
#include <SFML/Graphics.hpp>

class SceneGame1 : public Scene
{
public:
	SceneGame1(sf::RenderWindow* window);

	void Awake() override;

	void CreatePlayer(sf::Texture* texture);

	bool PauseMenu(bool gamePause);

	//TODO: ajouter la texture
	void CreatePlatform();
	void Create() override;
	void Update(sf::Time _delta) override;
	void Render(sf::RenderWindow* _window) override;

private:
	GameObject* platforme = nullptr;
	GameObject* player = nullptr;
	sf::Texture* texture;
	bool gamePause;
	bool is_press = true;
};

