#include "Scenes/SceneGame1.h"
#include "SceneManager.h"
#include "Components/SquareCollider.h"
#include "Components/Gravity.h"
#include "AssetManager.h"
#include "Components/SpriteRenderer.h"
#include "Components/Button.h"
#include "Scenes/SceneMainMenu.h"

std::map<std::string, sf::Texture> AssetManager::assets;

SceneGame1::SceneGame1(sf::RenderWindow* _window) : Scene(_window) {
	this->Awake();
	Scene::Create();
	std::cout << "Main menu" << std::endl;
}

bool SceneGame1::PauseMenu(bool gamePause)
{
	return gamePause;
};

void SceneGame1::CreateSceneGameButtons() {
	float widthScreen = SceneManager::GetWindow()->getSize().x;
	float heightScreen = SceneManager::GetWindow()->getSize().y;
	pausePlayButton = CreateButtonGameObject("Continue", widthScreen / 2, heightScreen / 3.5, 50);
	pauseMenuPrincipalButton = CreateButtonGameObject("Menu Principal", widthScreen / 2, heightScreen / 2, 50);
	pauseOptionsButton = CreateButtonGameObject("Options", widthScreen / 2, heightScreen / 1.5, 50);
	pauseQuitButton = CreateButtonGameObject("Quit", widthScreen / 2, heightScreen / 1.2, 50);
	

}

void SceneGame1::Create() {
	Scene::Create();
	this->CreatePlayer(sf::Texture());
	this->CreateGrunt(sf::Texture());
	CreatePlatform();
}

void SceneGame1::Awake() {
	Scene::Awake();
}

void SceneGame1::CreatePlayer(sf::Texture* imagePlayer) {
	player = CreateCharacterGameObject("Player", 400.f, 400.f, AssetManager::GetAsset("Player0"), 2.5f, 2.5f);
}

	this->player = CreateCharacterGameObject("Player", 400.f, 400.f, imagePlayer, 2.5f, 2.5f);
}

void SceneGame1::CreateGrunt(sf::Texture imageGrunt) 
{
	std::cout << "pas d'image" << std::endl;
	if (!imageGrunt.loadFromFile("../assets/Sprite/enemy/grunt.png")) 
	{
		std::cout << "pas d'image ennemy" << std::endl;
	}
	this->grunt = CreateGruntGameObject("Grunt", 0.f, 0.f,  2.5f, 2.5f, imageGrunt, this->player);;
}

void SceneGame1::Collision(GameObject* _entity)
{
	if (SquareCollider::IsColliding(*(_entity->GetComponent<SquareCollider>()), *(platforme1->GetComponent<SquareCollider>())) ||
		SquareCollider::IsColliding(*(_entity->GetComponent<SquareCollider>()), *(platforme2->GetComponent<SquareCollider>())) ||
		SquareCollider::IsColliding(*(_entity->GetComponent<SquareCollider>()), *(platforme3->GetComponent<SquareCollider>()))
		) 
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
		this->CreateSceneGameButtons();
		this->player->SetActive(false);
		this->grunt->SetActive(false);
		this->platforme1->SetActive(false);
		this->platforme2->SetActive(false);
		this->platforme3->SetActive(false);
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
		this->platforme1->SetActive(true);
		this->platforme2->SetActive(true);
		this->platforme3->SetActive(true);
	}
}

void SceneGame1::Update(sf::Time _delta) {

	SceneGame1::ManageSceneGameButtons();

	if (!gamePause)
	{
		Scene::Update(_delta);
		this->Collision(this->player);
		this->Collision(this->grunt);
	}
	else
	{
		if (pausePlayButton->GetComponent<Button>()->IsClicked()) {
			gamePause = false;
			escapeIsPress = true;
			this->player->SetActive(true);
			this->pausePlayButton->SetActive(false);
			this->pauseMenuPrincipalButton->SetActive(false);
			this->pauseOptionsButton->SetActive(false);
			this->pauseQuitButton->SetActive(false);
			this->platforme->SetActive(true);
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

void SceneGame1::CreatePlatform() {
	this->platforme1 = CreatePlatformObject("platforme1", 100.f, 500.f, 400.f, 50.f);
	this->platforme2 = CreatePlatformObject("platforme2", 600.f, 600.f, 700.f, 50.f);
	this->platforme3 = CreatePlatformObject("platforme3", 1400.f, 500.f, 400.f, 50.f);
}

void SceneGame1::Render(sf::RenderWindow* _window) {
	Scene::Render(_window);
}