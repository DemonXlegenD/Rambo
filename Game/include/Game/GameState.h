#pragma once
#include <SFML/Graphics.hpp>

class GameState
{
public:
	GameState(sf::RenderWindow* _window, int* _FPS);
	sf::Clock GetClock() const { return clock; }


	void Preload();
	void Update();
	void Create();

	~GameState();
private:
	sf::Clock clock;

	int* FPS;
	sf::RenderWindow* window;
};

