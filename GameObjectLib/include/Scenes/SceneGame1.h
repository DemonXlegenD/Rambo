#pragma once
#include "Scene.h"
#include <SFML/Graphics.hpp>

class SceneGame1 : public Scene
{
public:
	SceneGame1(sf::RenderWindow* window);

	void Awake() override;

	void CreatePlayer(sf::Texture* texture);

	void CreateGrunt(sf::Texture* texture);

	void CollisionPlayer();

	void CollisionGrunt();
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
	sf::Texture* texture;
};

