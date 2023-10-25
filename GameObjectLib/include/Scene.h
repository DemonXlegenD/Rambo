#pragma once
#include <SFML/Graphics/RenderWindow.hpp>

#include "GameObject.h"

class Scene
{
public:
	Scene() = default;
	virtual ~Scene() = default;

	void Update(sf::Time delta);
	void Render(sf::RenderWindow* _window);

	GameObject* CreateGameObject(const std::string& _name);

	GameObject* CreateCharacterGameObject(const std::string& name, float positionx, float positiony, const sf::Texture texture, float scalex, float scaley);

private:
	std::vector<GameObject*> gameObjects;
};
