#pragma once
#include "Scene.h"

class SceneMainMenu : public Scene
{
public:
	SceneMainMenu(sf::RenderWindow* window);
	void createSceneButtons();
	void Update(sf::Time _delta) override;
	~SceneMainMenu();
private:
	GameObject* playButton = nullptr;
	GameObject* optionsButton = nullptr;
	GameObject* quitButton = nullptr;
};

