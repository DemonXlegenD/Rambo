#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Scenes/SceneMainMenu.h"

class GameConfig
{
public:

	GameConfig();
	int getFps() const { return FPS; }
	sf::Clock getClock() const { return clock; }
	sf::RenderWindow* getWindow() const { return window; }
	sf::RenderWindow* setWindow(sf::RenderWindow* _window) { window = _window; }

	Scene* getActualScene() const { return actualScene; }

	void Preload();
	void Update();

	~GameConfig();

private:

	int FPS = 60;
	sf::Clock clock;
	sf::RenderWindow* window;

	std::map<std::string, Scene*> scenes;
	Scene* actualScene = nullptr;
};

