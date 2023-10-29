#pragma once
#include <iostream>
#include <map>
#include "Scene.h"

class SceneManager
{
public:

	//Add a new scene to the scene list
	static void AddScene(std::string _key, Scene _scene);

	//Run a scene
	static void RunScene(std::string _key) {
		if (SceneManager::scenes.find(_key) != SceneManager::scenes.end()) {
			if (SceneManager::activeScene) {
				SceneManager::StopScene();
			}
			SceneManager::activeScene = scenes.at(_key);
			//SceneManager::activeScene->Create();
			/*if (SceneMainMenu* sceneMainMenu = dynamic_cast<SceneMainMenu*>(SceneManager::activeScene)) {
				sceneMainMenu->Create();
			}
			else if (SceneGame1* sceneGame1 = dynamic_cast<SceneGame1*>(SceneManager::activeScene)) {
				sceneGame1->Create();
			}*/
		}
	}

	//Stop a scene (don't forget to run a scene after calling this function)	
	static void StopScene();

	//Get the current scene
	static Scene* GetActiveScene() { return activeScene; }

	static sf::RenderWindow* GetWindow() { return window; }
	static void SetWindow(sf::RenderWindow* _window) { window = _window; }

	~SceneManager();

private:
	static std::map<std::string, Scene*> scenes;
	static Scene* activeScene;
	static sf::RenderWindow* window;
};

