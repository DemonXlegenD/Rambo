#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Scene.h"

class GameConfig
{
public:

	GameConfig();
	int getFps() const { return FPS; }
	sf::Clock getClock() const { return clock; }
	sf::RenderWindow* getWindow() const { return window; }

	Scene* getActualScene() const { return actualScene; }

	void Preload();
	void Update();

	~GameConfig();

private:

	int FPS = 120;
	sf::Clock clock;
	sf::RenderWindow* window = nullptr;

	std::map<std::string, Scene*> scenes;
	Scene* actualScene = nullptr;
};

