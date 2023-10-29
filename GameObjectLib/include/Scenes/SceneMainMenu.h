#pragma once
#include "Scene.h"

class SceneMainMenu : public Scene
{
public:
	SceneMainMenu(sf::RenderWindow* window);


	void CreateSceneButtons();
	void CreatePlayer(sf::Texture* texture);
	void CreateBullet(sf::Texture* textureBullet);

	void Create() override;
	void Render(sf::RenderWindow* _window) override;
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

