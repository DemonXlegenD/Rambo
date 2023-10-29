#include "Scenes/SceneGame1.h"
#include "Components/SquareCollider.h"
#include "Components/Gravity.h"

SceneGame1::SceneGame1(sf::RenderWindow* _window) : Scene(_window) {
	this->Awake();
}

void SceneGame1::Create() {
	Scene::Create();
	texture = new sf::Texture();
	this->CreatePlayer(texture);
	this->CreatePlatform();
}

void SceneGame1::Awake() {
	Scene::Awake();
}

void SceneGame1::CreatePlayer(sf::Texture* imagePlayer) {
	if (!imagePlayer->loadFromFile("../assets/Sprite/player/john_static.png")) {
		std::cout << "pas d'image" << std::endl;
	}

	player = CreateCharacterGameObject("Player", 400.f, 400.f, *imagePlayer, 2.5f, 2.5f);
}

void SceneGame1::CreatePlatform() {
	platforme = CreatePlatformObject("platform", 0.0f, 900.0f, 1000.f, 50.f);
}

void SceneGame1::Update(sf::Time _delta) {
	Scene::Update(_delta);
	if (SquareCollider::IsColliding(*(player->GetComponent<SquareCollider>()), *(platforme->GetComponent<SquareCollider>()))) {
		player->GetComponent<Gravity>()->Stop();
	}
	else {
		player->GetComponent<Gravity>()->Start();
	}
}


void SceneGame1::Render(sf::RenderWindow* _window) {
	Scene::Render(_window);
}