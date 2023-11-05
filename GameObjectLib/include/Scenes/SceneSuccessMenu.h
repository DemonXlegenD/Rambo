#pragma once
#include "Scene.h"

class SceneSuccessMenu : public Scene
{
public:
	SceneSuccessMenu(sf::RenderWindow* window);

	void CreateSceneButtonsMenu();

	void SetOrigin();

	void Create() override;
	void Render(sf::RenderWindow* _window) override;
	void Update(sf::Time _delta) override;
private:
	GameObject* successButton = nullptr;
	GameObject* backButton = nullptr;
	GameObject* firstSuccessButton = nullptr;
	GameObject* firstSuccessBonusButton = nullptr;
	sf::Text text;
};

