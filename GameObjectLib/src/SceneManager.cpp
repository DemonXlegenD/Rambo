#include "SceneManager.h"

Scene* SceneManager::activeScene = nullptr;
sf::RenderWindow* SceneManager::window = nullptr;
std::map<std::string, Scene*> SceneManager::scenes;


void SceneManager::StopScene() {
	SceneManager::activeScene = nullptr; 
}

void SceneManager::RunScene(std::string _key) {
	if (SceneManager::scenes.find(_key) != SceneManager::scenes.end()) {
		if (SceneManager::activeScene) {
			SceneManager::StopScene();
		}
		SceneManager::activeScene = scenes.at(_key);
		std::cout << activeScene << std::endl;
		if (SceneMainMenu* sceneMainMenu = dynamic_cast<SceneMainMenu*>(SceneManager::activeScene)) {
			std::cout << "main menu" << std::endl;
			sceneMainMenu->Create();
		}
		else if (SceneGame1* sceneGame1 = dynamic_cast<SceneGame1*>(SceneManager::activeScene)) {
			std::cout << "game" << std::endl;
			sceneGame1->Create();
		}
		else {
			std::cout << "rien" << std::endl;
		}
	}
}

SceneManager::~SceneManager() {
	delete activeScene;
}