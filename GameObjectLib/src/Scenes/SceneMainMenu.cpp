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
	sf::Texture backgroundTexture1;
	sf::Texture backgroundTexture2;
	if (!backgroundTexture1.loadFromFile("../assets/Sprite/background/background_color.png"))
	{
		std::cout << "pas d'image" << std::endl;
	}
	if (!backgroundTexture2.loadFromFile("../assets/Sprite/background/jungle_bg_trees.png"))
	{
		std::cout << "pas d'image" << std::endl;
	}
	GameObject* background1 = CreateBackgroundGameObject("Background1", 0, 0, backgroundTexture1);
	GameObject* background2 = CreateBackgroundGameObject("Background2", 0, 0, backgroundTexture2);
	this->CreateSceneButtonsMenu();
	
	
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

void SceneMainMenu::CreateSceneButtonsMenu () {
	float widthScreen = SceneManager::GetWindow()->getSize().x;
	float heightScreen = SceneManager::GetWindow()->getSize().y;
	playButton = CreateButtonGameObject("Play", widthScreen / 2, heightScreen / 3, 50);
	quitButton = CreateButtonGameObject("Quit", widthScreen / 2, heightScreen / 1.5, 50);
	optionsButton = CreateButtonGameObject("Options", widthScreen / 2, heightScreen / 2, 20);

}

void SceneMainMenu::CreateMenuOption() {
	sf::Color colorAlpha(0, 0, 0, 128);
	GameObject* menuOption = CreateBackgroundGameObject("MenuOptionBackground", 0, 0, colorAlpha);

}

void SceneMainMenu::Update(sf::Time _delta) {
	Scene::Update(_delta);
	if (playButton->GetComponent<Button>()->IsClicked()) {
		SceneManager::RunScene("SceneGame1");
	}
	if (optionsButton->GetComponent<Button>()->IsClicked()) {
		this->CreateMenuOption();
	}
	if (quitButton->GetComponent<Button>()->IsClicked()) {
		SceneManager::GetWindow()->close();
	}

}

SceneMainMenu::~SceneMainMenu() {
	delete texture;
	delete textureBullet;
}