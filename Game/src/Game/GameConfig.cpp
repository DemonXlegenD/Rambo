#include "Game/GameConfig.h"
#include "SceneManager.h"

GameConfig::GameConfig() {
	this->FPS = 60;
	this->window = new sf::RenderWindow(sf::VideoMode(600, 600), "RAMBO", sf::Style::Fullscreen);
	SceneManager::SetWindow(this->window);
}

GameConfig::~GameConfig() {
	delete window;
}
