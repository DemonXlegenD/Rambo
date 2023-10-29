#include "Scenes/SceneMainMenu.h"
#include "SceneManager.h"
#include "Components/Button.h"

SceneMainMenu::SceneMainMenu(sf::RenderWindow* _window) : Scene(_window) {
	texture = nullptr;
	textureBullet = nullptr;
}

void SceneMainMenu::Create() {
	Scene::Create();
	std::cout << "Main menu" << std::endl;
	this->CreateSceneButtons();
}

void SceneMainMenu::Render(sf::RenderWindow* _window) {
	Scene::Render(_window);
}



void SceneMainMenu::CreatePlayer(sf::Texture* imagePlayer) {
	if (!imagePlayer->loadFromFile("../assets/Sprite/player/john_static.png")) {
		std::cout << "pas d'image" << std::endl;
	}

	player = CreateCharacterGameObject("Player", 400.f, 400.f, *imagePlayer, 2.5f, 2.5f);
}

void SceneMainMenu::CreateBullet(sf::Texture* imageBullet) {
	if (!imageBullet->loadFromFile("../assets/Sprite/player/weaponBullet/weapon_bullet_0.png")) {
		std::cout << "pas d'image" << std::endl;
	}

	bullet = CreateBulletGameObject("Player", *imageBullet, 2.5f, 2.5f, player);
}

void SceneMainMenu::CreateSceneButtons() {
	float widthScreen = SceneManager::GetWindow()->getSize().x;
	float heightScreen = SceneManager::GetWindow()->getSize().y;
	playButton = CreateButtonGameObject("Play", widthScreen / 2, heightScreen / 3, 50);
	quitButton = CreateButtonGameObject("Quit", widthScreen / 2, heightScreen / 1.5, 50);
	optionsButton = CreateButtonGameObject("Options", widthScreen / 2, heightScreen / 2, 20);

}

void SceneMainMenu::Update(sf::Time _delta) {
	Scene::Update(_delta);
	if (playButton->GetComponent<Button>()->IsClicked()) {
		SceneManager::RunScene("SceneGame1");
	}
	if (optionsButton->GetComponent<Button>()->IsClicked()) {
		std::cout << "Nothing here" << std::endl;
	}
	if (quitButton->GetComponent<Button>()->IsClicked()) {
		SceneManager::GetWindow()->close();
	}
}

SceneMainMenu::~SceneMainMenu() {
	delete texture;
	delete textureBullet;
}