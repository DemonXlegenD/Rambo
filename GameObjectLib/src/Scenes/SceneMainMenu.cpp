#include "Scenes/SceneMainMenu.h"
#include "SceneManager.h"
#include "Components/Button.h"
#include "Components/Slider.h"
#include "AudioManager.h"

SceneMainMenu::SceneMainMenu(sf::RenderWindow* _window) : Scene(_window) {
	texture = nullptr;
	textureBullet = nullptr;
}

void SceneMainMenu::Create() {
	Scene::Create();
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

	GameObject* background1 = CreateBackgroundGameObject("Background1", SceneManager::GetWindowWidth() / 2, SceneManager::GetWindowHeight() / 2, backgroundTexture1);
	GameObject* background2 = CreateBackgroundGameObject("Background2", SceneManager::GetWindowWidth() / 2, SceneManager::GetWindowHeight() / 2, backgroundTexture2);
	this->CreateSceneButtonsMenu();
	this->activeOption(false);
	this->activeMenu(true);

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
	optionsButton = CreateButtonGameObject("Options", widthScreen / 2, heightScreen / 2, 20);
	quitButton = CreateButtonGameObject("Quit", widthScreen / 2, heightScreen / 1.5, 50);
	backButton = CreateButtonGameObject("Back", widthScreen / 10, heightScreen / 10, 20);
	sliderFPS = CreateSliderGameObject("SliderFPS", widthScreen / 2, heightScreen / 2, 1200, 40, 50, 50, 20, SceneManager::GetFps(), SceneManager::GetMinFps(), SceneManager::GetMaxFps());
	sliderVolume = CreateSliderGameObject("SliderVolume", widthScreen / 2, heightScreen / 1.5, 1200, 40, 50, 50, 20, AudioManager::GetVolume(), AudioManager::GetMaxVolume());
}

void SceneMainMenu::Update(sf::Time _delta) {
	Scene::Update(_delta);
	if (playButton->GetComponent<Button>()->IsClicked()) {
		SceneManager::RunScene("SceneGame2");
	}
	if (optionsButton->GetComponent<Button>()->IsClicked() && optionsButton->GetActive()) {
		this->activeMenu(false);
		this->activeOption(true);
	}
	if (quitButton->GetComponent<Button>()->IsClicked() && quitButton->GetActive()) {
		SceneManager::GetWindow()->close();
	}
	if (backButton->GetComponent<Button>()->IsClicked() && backButton->GetActive()) {
		this->activeOption(false);
		this->activeMenu(true);
	}
	SceneManager::SetFps(sliderFPS->GetComponent<Slider>()->GetDataInt());
	AudioManager::SetVolume(sliderVolume->GetComponent<Slider>()->GetDataInt());
}

void SceneMainMenu::activeMenu(bool _state) {
	this->playButton->SetActive(_state);
	this->optionsButton->SetActive(_state);
	this->quitButton->SetActive(_state);
}

void SceneMainMenu::activeOption(bool _state) {
	this->backButton->SetActive(_state);
	this->sliderFPS->SetActive(_state);
	this->sliderVolume->SetActive(_state);
}

SceneMainMenu::~SceneMainMenu() {
	delete texture;
	delete textureBullet;
}