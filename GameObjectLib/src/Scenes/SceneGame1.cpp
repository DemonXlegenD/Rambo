#include "Scenes/SceneGame1.h"

SceneGame1::SceneGame1(sf::RenderWindow* _window) : Scene(_window) {
	this->Awake();
	texture = new sf::Texture();
	this->createPlayer(texture);
}

void SceneGame1::Awake() {
	platforme = CreatePlatformObject("platform", 0.0f, 900.0f, 1000.f, 50.f);
}
void SceneGame1::createPlayer(sf::Texture* imagePlayer) {
	if (!imagePlayer->loadFromFile("../assets/Sprite/player/john_static.png")) {
		std::cout << "pas d'image" << std::endl;
	}

	player = CreateCharacterGameObject("Player", 400.f, 400.f, *imagePlayer, 2.5f, 2.5f);
}

void SceneGame1::Update(sf::Time _delta) {
	Scene::Update(_delta);
	if (SquareCollider::IsColliding(*(player->GetComponent<SquareCollider>()), *(platforme->GetComponent<SquareCollider>()))) {
		//std::cout << player->getGravity()->isPlaying << std::endl;
		player->GetComponent<Gravity>()->stop();

		std::cout << "UWU" << std::endl;
	}
}


//void SceneGame1::Render(sf::RenderWindow* _window) {
//
//}
