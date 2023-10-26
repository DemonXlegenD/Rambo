#include "Scenes/SceneMainMenu.h"

SceneMainMenu::SceneMainMenu(sf::RenderWindow* _window) : Scene(_window) {
	this->createSceneButtons();
}

void SceneMainMenu::Update(sf::Time _delta) {
	Scene::Update(_delta);
	
}

void SceneMainMenu::createSceneButtons() {
	float widthScreen = Scene::GetWindow()->getSize().x;
	float heightScreen = Scene::GetWindow()->getSize().y;
	playButton = CreateButtonGameObject("Play", widthScreen / 2, heightScreen / 3, 50);
	optionsButton = CreateButtonGameObject("Options", widthScreen / 2, heightScreen / 2, 20);
	quitButton = CreateButtonGameObject("Quit", widthScreen / 2, heightScreen /1.5, 50);
} 

SceneMainMenu::~SceneMainMenu() {}