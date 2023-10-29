#include "SceneManager.h"

Scene* SceneManager::activeScene = nullptr;
sf::RenderWindow* SceneManager::window = nullptr;
std::map<std::string, Scene*> SceneManager::scenes;

void SceneManager::AddScene(std::string _key, Scene _scene) {
	SceneManager::scenes.insert(std::make_pair(_key, new Scene(_scene))); 
}

void SceneManager::StopScene() {
	SceneManager::activeScene = nullptr; 
}

SceneManager::~SceneManager() {
	delete activeScene;
}