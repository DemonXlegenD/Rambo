#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

#include <SFML/Graphics.hpp>

#include "GameObject.h"

#include "Components/Button.h"
#include "Components/InputPlayer.h"
#include "Components/SpriteRenderer.h"
#include "Components/SquareCollider.h"
#include "Components/Platforme.h"
#include "Components/Gravity.h"

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

	static Scene* getScene() { return scene; }
	static void setScene(Scene* _scene) { scene = _scene; }

	GameObject* CreateGameObject(const std::string& _name);

	GameObject* CreateCharacterGameObject(const std::string& name, float positionx, float positiony, const sf::Texture texture, float scalex, float scaley);

	GameObject* CreateGruntGameObject(const std::string& _name);

	GameObject* CreateGruntGameObject(const std::string& name, float position, const sf::Texture texture, float scalex, float scaley);

	GameObject* CreateButtonGameObject(const std::string& name, float x, float y, unsigned int fontSize);


	GameObject* CreatePlatformObject(const std::string& name, float x, float y, float scaleX, float scaleY);
	

	GameObject* CreateBulletGameObject(const std::string& name, const sf::Texture textureBullet, float scalex, float scaley, GameObject* _player);


protected:
	static Scene* scene;
	std::vector<GameObject*> gameObjects;
	static sf::RenderWindow* window;
	std::vector<GameObject*> gameObjectsGrunt;
	InputPlayer* inputHandlerPlayer;
	bool balleTiree;
	sf::Clock clock;
	sf::Time interval;
};
