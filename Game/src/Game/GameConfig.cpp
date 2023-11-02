#include "Game/GameConfig.h"
#include "SceneManager.h"
#include "AudioManager.h"


GameConfig::GameConfig() {
	this->FPS = 60;
	this->window = new sf::RenderWindow(sf::VideoMode(600, 600), "RAMBO", sf::Style::Fullscreen);
	SceneManager::SetWindow(this->window);
	AudioManager::AddMusic(std::string("valkyrieApocalypse"), std::string("../Sounds/valkyrie.mp3"));
	AudioManager::Play(std::string("valkyrieApocalypse"));
}

GameConfig::~GameConfig() {
	delete window;
}
