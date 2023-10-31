#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

#include <SFML/Graphics.hpp>

#include "GameObject.h"

#include "Components/Player.h"

#include "Components/Inputs/InputPlayer.h"

class Scene
{
public:
	Scene() = default;
	virtual ~Scene() = default;

	Scene(sf::RenderWindow* _window);

	virtual void Create();
	virtual void Update(sf::Time _delta);
	virtual void Render(sf::RenderWindow* _window);

	virtual void Awake();

	GameObject* getGameObject(std::string objectName) 
	{
		for (GameObject* gameObject : gameObjects) {
			if (gameObject->GetName() == objectName) {
				return gameObject;
			}
		}
		return nullptr; // Renvoie nullptr si aucun Collider n'est trouvé
	}

	GameObject* CreateGameObject(const std::string& _name);

	//PLAYER 
	GameObject* CreateCharacterGameObject(const std::string& name, float positionx, float positiony, const sf::Texture texture, float scalex, float scaley);
	GameObject* CreateBulletGameObject(const std::string& name, const sf::Texture textureBullet, float scalex, float scaley, GameObject* _player);

	GameObject* CreateGruntGameObject(const std::string& name, float positionx, float positiony, float scalex, float scaley, sf::Texture _texture, GameObject* _player);

	//GAME ELEMENT
	GameObject* CreateButtonGameObject(const std::string& name, float x, float y, unsigned int fontSize);
	GameObject* CreatePlatformObject(const std::string& name, float x, float y, float scaleX, float scaleY);

	GameObject* CreateBackgroundGameObject(const std::string& name, float x, float y, sf::Color _color);
	GameObject* CreateBackgroundGameObject(const std::string& name, float x, float y, sf::Texture texture);


protected:
	std::vector<GameObject*> gameObjects;
	static sf::RenderWindow* window;
	std::vector<GameObject*> gameObjectsGrunt;
	InputPlayer* inputHandlerPlayer;
	bool balleTiree;
	sf::Clock clock;
	sf::Time interval;
};
