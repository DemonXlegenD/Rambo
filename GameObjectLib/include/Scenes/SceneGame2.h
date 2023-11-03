#pragma once
#include <SFML/Graphics.hpp>

#include "Scene.h"
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h> 

class SceneGame2 : public Scene
{
public:
	SceneGame2(sf::RenderWindow* window);

	void Awake() override;

	void CreatePlayer();
	void CreateGrunt();
	void CreateTurret(sf::Texture texture);

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
	std::vector<GameObject*> platforms;
	std::vector<GameObject*> grunts;
	GameObject* turret1 = nullptr;
	GameObject* turret2 = nullptr;
	GameObject* player = nullptr;
	GameObject* pausePlayButton = nullptr;
	GameObject* pauseOptionsButton = nullptr;
	GameObject* pauseMenuPrincipalButton = nullptr;
	GameObject* pauseQuitButton = nullptr;
	sf::Texture* texture;
	bool gamePause;
	bool escapeIsPress = true;
};


