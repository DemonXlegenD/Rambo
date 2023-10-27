#pragma once
#include "Scene.h"

class SceneMainMenu : public Scene
{
public:
	SceneMainMenu(sf::RenderWindow* window);
	void createSceneButtons();
	void createPlayer(sf::Texture* texture);
	void createBullet(sf::Texture* textureBullet);
	void Update(sf::Time _delta) override;
	~SceneMainMenu();
private:
	GameObject* playButton = nullptr;
	GameObject* optionsButton = nullptr;
	GameObject* quitButton = nullptr;
	GameObject* player = nullptr;
	GameObject* bullet = nullptr;
	sf::Texture* texture;
	sf::Texture* textureBullet;
};

