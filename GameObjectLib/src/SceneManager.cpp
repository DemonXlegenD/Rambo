#include "SceneManager.h"

Scene* SceneManager::activeScene = nullptr;
sf::RenderWindow* SceneManager::window = nullptr;
std::map<std::string, Scene*> SceneManager::scenes;


void SceneManager::StopScene() {
	SceneManager::activeScene = nullptr; 
}

SceneManager::~SceneManager() {
	delete activeScene;
}