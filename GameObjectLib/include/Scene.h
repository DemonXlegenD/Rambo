#pragma once

#include <SFML/Graphics/RenderWindow.hpp>


#include "GameObject.h"
#include "Components/Button.h"
#include "Components/SpriteRenderer.h"

#include "Components/SquareCollider.h"
#include "Components/InputPlayer.h"
//#include "Enemy/Grunt.h"



class Scene
{
public:
	Scene() = default;
	virtual ~Scene() = default;

	Scene(sf::RenderWindow* _window);

	virtual void Update(sf::Time _delta);
	virtual void Render(sf::RenderWindow* _window);

	virtual void Awake();
	static sf::RenderWindow* GetWindow() { return window; }
	static void SetWindow(sf::RenderWindow* _window) { window = _window; }

	GameObject* CreateGameObject(const std::string& _name);

	GameObject* CreateCharacterGameObject(const std::string& name, float positionx, float positiony, const sf::Texture texture, float scalex, float scaley);

	GameObject* CreateGruntGameObject(const std::string& _name);

	GameObject* CreateGruntGameObject(const std::string& name, float position, const sf::Texture texture, float scalex, float scaley);

	GameObject* CreateButtonGameObject(const std::string& name, float x, float y, unsigned int fontSize);


protected:
	std::vector<GameObject*> gameObjects;
	static sf::RenderWindow* window;
	std::vector<GameObject*> gameObjectsGrunt;
	InputPlayer* inputHandlerPlayer;
};
