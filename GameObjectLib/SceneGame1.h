#pragma once
#include "Scene.h"
class SceneGame1 : public Scene
{
public:
	SceneGame1(sf::RenderWindow* window);

	void Awake() override;
	void Update(sf::Time _delta) override;
	void Render(sf::RenderWindow* _window) override; 

	void createSceneButtons();

	~SceneGame1();

private :
	GameObject* pause = nullptr;
};

