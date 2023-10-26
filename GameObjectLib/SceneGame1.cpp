#include "SceneGame1.h"

SceneGame1::SceneGame1(sf::RenderWindow* _window) : Scene(_window) {
	this->createSceneButtons();
}

void SceneGame1::Awake() {

}

void SceneGame1::Update(sf::Time _delta){

}

void SceneGame1::Render(sf::RenderWindow* _window) {

}

void SceneGame1::createSceneButtons() {
	pause = CreateButtonGameObject(, 1200.0f, 900.0f, 50);
}