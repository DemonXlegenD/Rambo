#pragma once

#include <iostream>
#include <map>

#include "Scene.h"
#include "Scenes/SceneGame1.h"
#include "Scenes/SceneMainMenu.h"

class SceneManager
{
public:

	//Add a new scene to the scene list
	template <typename T> 
	static void AddScene(std::string _key, T* _scene) {
		SceneManager::scenes.insert(std::make_pair(_key, _scene));
	}

	static int GetFps() { return fps; }
	static int GetMaxFps() { return maxFps; }
	static int GetMinFps() { return minFps; }
	static void SetFps(int _fps) { fps = _fps; }
	static void SetMinFps(int& _minFps) { minFps = _minFps; }
	static void SetMaxFps(int& _maxFps) { maxFps = _maxFps; }
	//Run a scene
	static void RunScene(std::string _key);

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
	static int fps;
	static int minFps;
	static int maxFps;
};

