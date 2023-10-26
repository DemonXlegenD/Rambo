#include "Scenes/SceneMainMenu.h"

SceneMainMenu::SceneMainMenu(sf::RenderWindow* _window) : Scene(_window) {
	this->createSceneButtons();
}

void SceneMainMenu::Update(sf::Time _delta) {
	Scene::Update(_delta);
	
}

void SceneMainMenu::createSceneButtons() {
	playButton = CreateButtonGameObject("Play", 1200.0f, 900.0f, 50);
	optionsButton = CreateButtonGameObject("Options", 1200.0f, 600.0f, 20);
	quitButton = CreateButtonGameObject("Quit", 1200.0f, 300.0f, 50);
} 

SceneMainMenu::~SceneMainMenu() {}