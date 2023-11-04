#include "Game/GameConfig.h"
#include "SceneManager.h"
//#include "AudioManager.h"


GameConfig::GameConfig() {
	this->FPS = 240;
	this->window = new sf::RenderWindow(sf::VideoMode(1900, 1080), "RAMBO");
	SceneManager::SetWindow(this->window);
	SceneManager::SetFps(this->FPS);
	//AudioManager::AddMusic(std::string("valkyrieApocalypse"), std::string("../Sounds/valkyrie.mp3"));
	//AudioManager::Play(std::string("valkyrieApocalypse"));
}

GameConfig::~GameConfig() {
	delete this->window;
}
