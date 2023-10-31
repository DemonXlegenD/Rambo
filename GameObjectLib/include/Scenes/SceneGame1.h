#pragma once
#include <SFML/Graphics.hpp>

#include "Scene.h"

class SceneGame1 : public Scene
{
public:
	SceneGame1(sf::RenderWindow* window);

	void Awake() override;

	void CreatePlayer(sf::Texture* texture);
	void CreateGrunt(sf::Texture* texture);

	void CollisionPlayer();

	void CollisionGrunt();

	bool PauseMenu(bool gamePause);
	void CreateSceneGameButtons();

	void ManageSceneGameButtons();


	//TODO: ajouter la texture
	void CreatePlatform();
	void Create() override;
	void Update(sf::Time _delta) override;
	void Render(sf::RenderWindow* _window) override;

private:
	GameObject* platforme1 = nullptr;
	GameObject* platforme2 = nullptr;
	GameObject* platforme3 = nullptr;
	GameObject* grunt = nullptr;
	GameObject* player = nullptr;
	GameObject* pausePlayButton = nullptr;
	GameObject* pauseOptionsButton = nullptr;
	GameObject* pauseQuitButton = nullptr;
	sf::Texture* texture;
	bool gamePause;
	bool escapeIsPress = true;
};

