#include "Scenes/SceneGame1.h"
#include "SceneManager.h"
#include "Components/SpriteRenderer.h"
#include "Components/SquareCollider.h"
#include "Components/Gravity.h"
#include "AssetManager.h"
#include "Components/SpriteRenderer.h"
#include "Components/Button.h"
#include "Scenes/SceneMainMenu.h"

SceneGame1::SceneGame1(sf::RenderWindow* _window) : Scene(_window) {
	this->Awake();
	Scene::Create();
	srand(time(nullptr));
}


bool SceneGame1::PauseMenu(bool gamePause)
{
	return gamePause;
};


void SceneGame1::Create() {
	Scene::Create();
	CreateBackground();
	this->CreateSceneGameButtons();
	this->CreatePlayer();
	this->CreateGrunt();
	CreatePlatform(sf::Texture());
}

void SceneGame1::CreateSceneGameButtons() {
	float widthScreen = SceneManager::GetWindow()->getSize().x;
	float heightScreen = SceneManager::GetWindow()->getSize().y;
	pausePlayButton = CreateButtonGameObject("Continue", widthScreen / 2, heightScreen / 3.5, 50);
	pauseMenuPrincipalButton = CreateButtonGameObject("Menu Principal", widthScreen / 2, heightScreen / 2, 50);
	pauseOptionsButton = CreateButtonGameObject("Options", widthScreen / 2, heightScreen / 1.5, 50);
	pauseQuitButton = CreateButtonGameObject("Quit", widthScreen / 2, heightScreen / 1.2, 50);
	this->pauseMenuPrincipalButton->SetActive(false);
	this->pausePlayButton->SetActive(false);
	this->pauseOptionsButton->SetActive(false);
	this->pauseQuitButton->SetActive(false);
}

void SceneGame1::Awake() {
	Scene::Awake();
}

void SceneGame1::CreatePlayer() {
	player = CreateCharacterGameObject("Player", 400.f, 400.f, AssetManager::GetAsset("Player0"), 2.5f, 2.5f);
}

void SceneGame1::CreateGrunt()
{
	int rand_Grunt1 = rand() % 700 + 100;
	int rand_Grunt2 = rand() % 700 + 100;
	int rand_Grunt3 = rand() % 1500 + 600;
	int rand_Grunt4 = rand() % 1500 + 600;
	int rand_Grunt5 = rand() % 1800 + 1400;
	int rand_Grunt6 = rand() % 1800 + 1400;

	grunts.push_back(CreateGruntGameObject("Grunt1", rand_Grunt1, 100.f, 2.5f, 2.5f, AssetManager::GetAsset("Grunt0")));
	grunts.push_back(CreateGruntGameObject("Grunt2", rand_Grunt2, 100.f, 2.5f, 2.5f, AssetManager::GetAsset("Grunt0")));
	grunts.push_back(CreateGruntGameObject("Grunt3", rand_Grunt3, 100.f, 2.5f, 2.5f, AssetManager::GetAsset("Grunt0")));
	grunts.push_back(CreateGruntGameObject("Grunt4", rand_Grunt4, 100.f, 2.5f, 2.5f, AssetManager::GetAsset("Grunt0")));
	grunts.push_back(CreateGruntGameObject("Grunt5", rand_Grunt5, 100.f, 2.5f, 2.5f, AssetManager::GetAsset("Grunt0")));
	grunts.push_back(CreateGruntGameObject("Grunt6", rand_Grunt6, 100.f, 2.5f, 2.5f, AssetManager::GetAsset("Grunt0")));
}

void SceneGame1::Collision(GameObject* _entity)
{
	bool colliding = false;
	for (GameObject* platform : platforms) {
		if (SquareCollider::IsColliding(*(_entity->GetComponent<SquareCollider>()), *(platform->GetComponent<SquareCollider>()))) {
			colliding = true;
			break;
		}
	}

	if (colliding)
	{
		_entity->GetComponent<Gravity>()->Stop();
	}
	else
	{
		_entity->GetComponent<Gravity>()->Start();
	}
}

void SceneGame1::ManageSceneGameButtons()
{
	Command* pauseInput = inputHandlerPlayer->PauseInput();
	if (pauseInput && escapeIsPress) {
		pauseInput->Execute();
		gamePause = true;
		escapeIsPress = false;
		this->player->SetActive(false);
		this->pauseMenuPrincipalButton->SetActive(true);
		this->pausePlayButton->SetActive(true);
		this->pauseOptionsButton->SetActive(true);
		this->pauseQuitButton->SetActive(true);
		for (GameObject* grunt : grunts) {
			grunt->SetActive(false);
		}
		for (GameObject* platform : platforms) {
			platform->SetActive(false);
		}
	}
	else if (pauseInput && !escapeIsPress) {
		pauseInput->Execute();
		gamePause = false;
		escapeIsPress = true;
		this->player->SetActive(true);
		this->pauseMenuPrincipalButton->SetActive(false);
		this->pausePlayButton->SetActive(false);
		this->pauseOptionsButton->SetActive(false);
		this->pauseQuitButton->SetActive(false);
		for (GameObject* grunt : grunts) {
			grunt->SetActive(true);
		}
		for (GameObject* platform : platforms) {
			platform->SetActive(true);
		}
	}
}

void SceneGame1::Update(sf::Time _delta) {

	SceneGame1::ManageSceneGameButtons();

	if (!gamePause)
	{
		Scene::Update(_delta);
		this->Collision(this->player);
		this->player->GetComponent<Sprite>()->PlayerPlayAnimation();
		for (GameObject* grunt : grunts) {
			this->Collision(grunt);
			grunt->GetComponent<Sprite>()->GruntPlayAnimation();
		}

		if (!this->player->GetComponent<Player>()->directionPlayer)
		{
			this->player->GetComponent<Sprite>()->SetScale(2.5f, 2.5f);
		}
		else
		{
			this->player->GetComponent<Sprite>()->SetScale(-2.5f, 2.5f);
		}
	}
	else
	{
		if (pausePlayButton->GetComponent<Button>()->IsClicked()) {
			gamePause = false;
			escapeIsPress = true;
			this->player->SetActive(true);
			this->pauseMenuPrincipalButton->SetActive(false);
			this->pausePlayButton->SetActive(false);
			this->pauseOptionsButton->SetActive(false);
			this->pauseQuitButton->SetActive(false);
			for (GameObject* grunt : grunts) {
				grunt->SetActive(true);
			}
			for (GameObject* platform : platforms) {
				platform->SetActive(true);
			}
		}
		if (pauseMenuPrincipalButton->GetComponent<Button>()->IsClicked()) {
			SceneManager::RunScene("SceneMainMenu");
		}
		if (pauseOptionsButton->GetComponent<Button>()->IsClicked()) {
			std::cout << "Options" << std::endl;
		}
		if (pauseQuitButton->GetComponent<Button>()->IsClicked()) {
			SceneManager::GetWindow()->close();
		}
	}
}

void SceneGame1::CreatePlatform(sf::Texture textureplatforme) {


	if (!textureplatforme.loadFromFile("../assets/Sprite/tiles_spritesheet.png"))
	{
		std::cout << "pas d'image ennemy" << std::endl;
	}

	sf::IntRect rectSource(200, 0, 95, 40);
	platforms.push_back(CreatePlatformObject("platforme1", 300.f, 700.f, 3.75f, 2.f, textureplatforme, new sf::IntRect(rectSource)));
	platforms.push_back(CreatePlatformObject("platforme2", 750.f, 900.f, 3.75f, 2.f, textureplatforme, new sf::IntRect(rectSource)));
	platforms.push_back(CreatePlatformObject("platforme3", 1100.f, 900.f, 3.75f, 2.f, textureplatforme, new sf::IntRect(rectSource)));
	platforms.push_back(CreatePlatformObject("platforme4", 1600.f, 700.f, 4.f, 2.f, textureplatforme, new sf::IntRect(rectSource)));;
}

void SceneGame1::CreateBackground()
{
	sf::Texture backgroundTexture1;

	if (!backgroundTexture1.loadFromFile("../assets/Sprite/background/background_color.png"))
	{
		std::cout << "pas d'image" << std::endl;
	}
	GameObject* background1 = CreateBackgroundGameObject("Background1", SceneManager::GetWindowWidth() / 2, SceneManager::GetWindowHeight() / 2, backgroundTexture1);
};

void SceneGame1::Render(sf::RenderWindow* _window) {
	Scene::Render(_window);
}