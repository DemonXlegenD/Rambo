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
	void SpawnGrunt();

	void Collision(GameObject* _entity);

	bool PauseMenu(bool gamePause);
	void CreateSceneGameButtons();

	void ManageSceneGameButtons();


	//TODO: ajouter la texture
	void CreatePlatform(sf::Texture texture);
	void CreateBackground();
	void Create() override;
	void Update(sf::Time _delta) override;
	void Render(sf::RenderWindow* _window) override;

private:
	GameObject* platforme1 = nullptr;
	GameObject* platforme2 = nullptr;
	GameObject* platforme3 = nullptr;
	GameObject* platforme4 = nullptr;
	GameObject* platforme5 = nullptr;
	GameObject* platforme6 = nullptr;
	GameObject* grunt1 = nullptr;
	GameObject* grunt2 = nullptr;
	GameObject* grunt3 = nullptr;
	GameObject* grunt4 = nullptr;
	GameObject* grunt5 = nullptr;
	GameObject* grunt6 = nullptr;
	GameObject* grunt7 = nullptr;
	GameObject* grunt8 = nullptr;
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


