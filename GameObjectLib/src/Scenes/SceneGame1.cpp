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
	this->pausePlayButton = CreateButtonGameObject("Continue", widthScreen / 2, heightScreen / 3, 50);
	this->pauseOptionsButton = CreateButtonGameObject("Quit", widthScreen / 2, heightScreen / 1.5, 50);
	this->pauseQuitButton = CreateButtonGameObject("Options", widthScreen / 2, heightScreen / 2, 20);

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

void SceneGame1::CreatePlayer(sf::Texture imagePlayer) {
	if (!imagePlayer.loadFromFile("../assets/Sprite/player/john_static.png")) {
		std::cout << "pas d'image" << std::endl;
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
		this->player->SetActive(true);
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
}

void SceneGame1::CreatePlatform() {
	this->platforme1 = CreatePlatformObject("platforme1", 100.f, 500.f, 400.f, 50.f);
	this->platforme2 = CreatePlatformObject("platforme2", 600.f, 600.f, 700.f, 50.f);
	this->platforme3 = CreatePlatformObject("platforme3", 1400.f, 500.f, 400.f, 50.f);
}

void SceneGame1::Render(sf::RenderWindow* _window) {
	Scene::Render(_window);
}