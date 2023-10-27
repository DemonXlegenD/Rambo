#include "Game.h"

Game::Game() {
	this->config = new GameConfig();
	this->state = new GameState();
	this->stats = new GameStats();
	this->log = new GameLog();
}

void Game::run() {

	sf::Texture ImageBongo;
	config->Preload();
	ImageBongo.loadFromFile("assets/Sprite/player/john_static.png");

	sf::RenderWindow* window = config->getWindow();

	while (window->isOpen())
	{

		config->Update();

	}
}