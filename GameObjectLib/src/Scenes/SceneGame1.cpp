#include "Scenes/SceneGame1.h"
#include "SceneManager.h"
#include "Components/SquareCollider.h"
#include "Components/Gravity.h"

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
	pausePlayButton = CreateButtonGameObject("Continue", widthScreen / 2, heightScreen / 3, 50);
	pauseOptionsButton = CreateButtonGameObject("Quit", widthScreen / 2, heightScreen / 1.5, 50);
	pauseQuitButton = CreateButtonGameObject("Options", widthScreen / 2, heightScreen / 2, 20);

}

void SceneGame1::Create() {
	Scene::Create();
	texture = new sf::Texture();
	this->CreatePlayer(texture);
	this->CreateGrunt(texture);
	CreatePlatform();
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

void SceneGame1::CreateGrunt(sf::Texture* imageGrunt) {
	std::cout << "pas d'image" << std::endl;
	if (!imageGrunt->loadFromFile("../assets/Sprite/enemy/grunt.png")) {
		std::cout << "pas d'image ennemy" << std::endl;
	}

	grunt = CreateGruntGameObject("Grunt", 0.f, 0.f, *imageGrunt, 2.5f, 2.5f);;
}

void SceneGame1::CollisionPlayer(){
	if (SquareCollider::IsColliding(*(player->GetComponent<SquareCollider>()), *(platforme1->GetComponent<SquareCollider>()))) {
		player->GetComponent<Gravity>()->Stop();
	}
	else if (
		SquareCollider::IsColliding(*(player->GetComponent<SquareCollider>()), *(platforme2->GetComponent<SquareCollider>()))) {
		player->GetComponent<Gravity>()->Stop();
	}
	else if (SquareCollider::IsColliding(*(player->GetComponent<SquareCollider>()), *(platforme3->GetComponent<SquareCollider>()))) {
		player->GetComponent<Gravity>()->Stop();
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
		this->platforme->SetActive(false);
	}
	else if (pauseInput && !escapeIsPress) {
		pauseInput->Execute();
		gamePause = false;
		escapeIsPress = true;
		this->player->SetActive(true);
		this->pausePlayButton->SetActive(false);
		this->pauseOptionsButton->SetActive(false);
		this->pauseQuitButton->SetActive(false);
		this->platforme->SetActive(true);
	}
}

void SceneGame1::Update(sf::Time _delta) {

	SceneGame1::ManageSceneGameButtons();

	if (!gamePause)
	{
		Scene::Update(_delta);
		if (SquareCollider::IsColliding(*(player->GetComponent<SquareCollider>()), *(platforme->GetComponent<SquareCollider>()))) {
			player->GetComponent<Gravity>()->Stop();
		}
		else {
			player->GetComponent<Gravity>()->Start();
		}
	}
}

void SceneGame1::CollisionGrunt() {
	if (SquareCollider::IsColliding(*(grunt->GetComponent<SquareCollider>()), *(platforme1->GetComponent<SquareCollider>()))) {
		grunt->GetComponent<Gravity>()->Stop();
	}
	
	else {
		grunt->GetComponent<Gravity>()->Start();
	}
}

void SceneGame1::CreatePlatform() {
	this->platforme1 = CreatePlatformObject("platforme1", 100.f, 500.f, 400.f, 50.f);
	this->platforme2 = CreatePlatformObject("platforme2", 600.f, 600.f, 700.f, 50.f);
	this->platforme3 = CreatePlatformObject("platforme3", 1400.f, 500.f, 400.f, 50.f);
}



void SceneGame1::Update(sf::Time _delta) {
	Scene::Update(_delta);
	CollisionPlayer();
	CollisionGrunt();
}


void SceneGame1::Render(sf::RenderWindow* _window) {
	Scene::Render(_window);
}