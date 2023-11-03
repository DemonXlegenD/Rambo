#pragma once
#include <SFML/Graphics.hpp>

#include "Scene.h"
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h>       

class SceneGame1 : public Scene
{
public:
	SceneGame1(sf::RenderWindow* window);

	void Awake() override;

	void CreatePlayer();
	void CreateGrunt();

	void Collision(GameObject* _entity);

	bool PauseMenu(bool gamePause);

	void ManageSceneGameButtons();
	void CreateSceneGameButtons();

	//TODO: ajouter la texture
	void CreatePlatform(sf::Texture texture);
	void CreateBackground();
	void Create() override;
	void Update(sf::Time _delta) override;
	void Render(sf::RenderWindow* _window) override;

private:
	//TODO : tout passer en vector
	std::vector<GameObject*> platforms;
	std::vector<GameObject*> grunts;
	GameObject* player = nullptr;
	GameObject* pausePlayButton = nullptr;
	GameObject* pauseOptionsButton = nullptr;
	GameObject* pauseMenuPrincipalButton = nullptr;
	GameObject* pauseQuitButton = nullptr;
	sf::Texture* texture ;
	bool gamePause;
	bool escapeIsPress = true;
};

