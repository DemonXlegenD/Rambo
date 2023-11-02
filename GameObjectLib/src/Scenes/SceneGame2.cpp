#include "Scenes/SceneGame2.h"
#include "SceneManager.h"
#include "Components/SpriteRenderer.h"
#include "Components/SquareCollider.h"
#include "Components/Gravity.h"
#include "AssetManager.h"
#include "Components/SpriteRenderer.h"
#include "Components/Button.h"
#include "Scenes/SceneMainMenu.h"

std::map<std::string, sf::Texture> AssetManager::assets;

SceneGame2::SceneGame2(sf::RenderWindow* _window) : Scene(_window) {
	this->Awake();
	Scene::Create();
	std::cout << "Main menu" << std::endl;
}

bool SceneGame2::PauseMenu(bool gamePause)
{
	return gamePause;
};

void SceneGame2::CreateSceneGameButtons() {
	float widthScreen = SceneManager::GetWindow()->getSize().x;
	float heightScreen = SceneManager::GetWindow()->getSize().y;
	pausePlayButton = CreateButtonGameObject("Continue", widthScreen / 2, heightScreen / 3.5, 50);
	pauseMenuPrincipalButton = CreateButtonGameObject("Menu Principal", widthScreen / 2, heightScreen / 2, 50);
	pauseOptionsButton = CreateButtonGameObject("Options", widthScreen / 2, heightScreen / 1.5, 50);
	pauseQuitButton = CreateButtonGameObject("Quit", widthScreen / 2, heightScreen / 1.2, 50);


}

void SceneGame2::Create() {
	Scene::Create();
	CreateBackground();
	this->CreatePlayer();
	this->CreateGrunt(sf::Texture());
	this->CreateTurret(sf::Texture());
	CreatePlatform(sf::Texture());
}

void SceneGame2::Awake() {
	Scene::Awake();
}

void SceneGame2::CreatePlayer() {
	player = CreateCharacterGameObject("Player", 100.f, 100.f, AssetManager::GetAsset("Player0"), 2.5f, 2.5f);
}

void SceneGame2::CreateGrunt(sf::Texture imageGrunt)
{
	std::cout << "pas d'image" << std::endl;
	if (!imageGrunt.loadFromFile("../assets/Sprite/enemy/grunt.png"))
	{
		std::cout << "pas d'image ennemy" << std::endl;
	}

	srand(time(nullptr));
	int rand_Grunt1 = rand() % 500 + 100;
	int rand_Grunt2 = rand() % 500 + 100;
	int rand_Grunt3 = rand() % 1300 + 600;
	int rand_Grunt4 = rand() % 1300 + 600;
	int rand_Grunt5 = rand() % 1300 + 600;
	int rand_Grunt6 = rand() % 1300 + 600;
	int rand_Grunt7 = rand() % 1800 + 1400;
	int rand_Grunt8 = rand() % 1800 + 1400;

	this->grunt1 = CreateGruntGameObject("Grunt1", rand_Grunt1, 100.f, 2.5f, 2.5f, imageGrunt);
	this->grunt2 = CreateGruntGameObject("Grunt2", rand_Grunt2, 100.f, 2.5f, 2.5f, imageGrunt);
	this->grunt3 = CreateGruntGameObject("Grunt3", rand_Grunt3, 100.f, 2.5f, 2.5f, imageGrunt);
	this->grunt4 = CreateGruntGameObject("Grunt4", rand_Grunt4, 100.f, 2.5f, 2.5f, imageGrunt);
	this->grunt5 = CreateGruntGameObject("Grunt5", rand_Grunt5, 100.f, 2.5f, 2.5f, imageGrunt);
	this->grunt6 = CreateGruntGameObject("Grunt6", rand_Grunt6, 100.f, 2.5f, 2.5f, imageGrunt);
	this->grunt7 = CreateGruntGameObject("Grunt6", rand_Grunt7, 100.f, 2.5f, 2.5f, imageGrunt);
	this->grunt8 = CreateGruntGameObject("Grunt6", rand_Grunt8, 100.f, 2.5f, 2.5f, imageGrunt);
}

void SceneGame2::CreateTurret(sf::Texture imageTurret)
{
	std::cout << "pas d'image" << std::endl;
	if (!imageTurret.loadFromFile("../assets/Sprite/enemy/turret/turret_0.png"))
	{
		std::cout << "pas d'image ennemy" << std::endl;
	}


	this->turret1 = CreateGruntGameObject("Turret1", 10, 100.f, 2.5f, 2.5f, imageTurret);
	this->turret2 = CreateGruntGameObject("Turret2", 1800, 100.f, 2.5f, 2.5f, imageTurret);

	this->turret1->GetComponent<Gravity>()->Stop();
	this->turret2->GetComponent<Gravity>()->Stop();
}

//void SceneGame1::SpawnGrunt()
//{
//	srand(time(nullptr));
//	int rand_Grunt1 = rand() % 500 + 100;
//	int rand_Grunt2 = rand() % 500 + 100;
//	int rand_Grunt3 = rand() % 1300 + 600;
//	int rand_Grunt4 = rand() % 1300 + 600;
//	int rand_Grunt5 = rand() % 1800 + 1400;
//	int rand_Grunt6 = rand() % 1800 + 1400;
//
//
//	this->CreateGrunt(sf::Texture(), rand_Grunt1, 500.f);
//	this->CreateGrunt(sf::Texture(), rand_Grunt2, 500.f);
//	this->CreateGrunt(sf::Texture(), rand_Grunt3, 600.f);
//	this->CreateGrunt(sf::Texture(), rand_Grunt4, 600.f);
//	this->CreateGrunt(sf::Texture(), rand_Grunt5, 500.f);
//	this->CreateGrunt(sf::Texture(), rand_Grunt6, 500.f);
//}

void SceneGame2::Collision(GameObject* _entity)
{
	if (SquareCollider::IsColliding(*(_entity->GetComponent<SquareCollider>()), *(platforme1->GetComponent<SquareCollider>())) ||
		SquareCollider::IsColliding(*(_entity->GetComponent<SquareCollider>()), *(platforme2->GetComponent<SquareCollider>())) ||
		SquareCollider::IsColliding(*(_entity->GetComponent<SquareCollider>()), *(platforme3->GetComponent<SquareCollider>())) ||
		SquareCollider::IsColliding(*(_entity->GetComponent<SquareCollider>()), *(platforme4->GetComponent<SquareCollider>())) ||
		SquareCollider::IsColliding(*(_entity->GetComponent<SquareCollider>()), *(platforme5->GetComponent<SquareCollider>())) ||
		SquareCollider::IsColliding(*(_entity->GetComponent<SquareCollider>()), *(platforme6->GetComponent<SquareCollider>()))
		)
	{
		_entity->GetComponent<Gravity>()->Stop();
	}
	else
	{
		_entity->GetComponent<Gravity>()->Start();
	}
}

void SceneGame2::ManageSceneGameButtons()
{
	Command* pauseInput = inputHandlerPlayer->PauseInput();
	if (pauseInput && escapeIsPress) {
		pauseInput->Execute();
		gamePause = true;
		escapeIsPress = false;
		this->CreateSceneGameButtons();
		this->player->SetActive(false);
		this->grunt1->SetActive(false);
		this->grunt2->SetActive(false);
		this->grunt3->SetActive(false);
		this->grunt4->SetActive(false);
		this->grunt5->SetActive(false);
		this->grunt6->SetActive(false);
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

void SceneGame2::Update(sf::Time _delta) {

	SceneGame2::ManageSceneGameButtons();

	if (!gamePause)
	{
		Scene::Update(_delta);
		this->Collision(this->player);
		this->Collision(this->grunt1);
		this->Collision(this->grunt2);
		this->Collision(this->grunt3);
		this->Collision(this->grunt4);
		this->Collision(this->grunt5);
		this->Collision(this->grunt6);
		this->Collision(this->grunt7);
		this->Collision(this->grunt8);
		this->player->GetComponent<Sprite>()->PlayerPlayAnimation();
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
			this->platforme1->SetActive(true);
			this->platforme2->SetActive(true);
			this->platforme3->SetActive(true);
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

void SceneGame2::CreatePlatform(sf::Texture textureplatforme) {


	if (!textureplatforme.loadFromFile("../assets/Sprite/cave_tileset.png"))
	{
		std::cout << "pas d'image ennemy" << std::endl;
	}

	sf::IntRect rectSource(16, 1, 63, 21);
	this->platforme1 = CreatePlatformObject("platforme1", 100.f, 500.f, 3.75f, 2.f, textureplatforme, new sf::IntRect(rectSource));
	this->platforme2 = CreatePlatformObject("platforme2", 600.f, 400.f, 3.75f, 2.f, textureplatforme, new sf::IntRect(rectSource));
	this->platforme3 = CreatePlatformObject("platforme3", 900.f, 400.f, 3.75f, 2.f, textureplatforme, new sf::IntRect(rectSource));
	this->platforme4 = CreatePlatformObject("platforme4", 1400.f, 500.f, 4.f, 2.f, textureplatforme, new sf::IntRect(rectSource));
	this->platforme5 = CreatePlatformObject("platforme5", 600.f, 600.f, 3.75f, 2.f, textureplatforme, new sf::IntRect(rectSource));
	this->platforme6 = CreatePlatformObject("platforme6", 900.f, 600.f, 3.75f, 2.f, textureplatforme, new sf::IntRect(rectSource));
}

void SceneGame2::CreateBackground()
{
	sf::Texture backgroundTexture1;

	if (!backgroundTexture1.loadFromFile("../assets/Sprite/background/background_cave.png"))
	{
		std::cout << "pas d'image" << std::endl;
	}
	GameObject* background1 = CreateBackgroundGameObject("Background1", 0, 0, backgroundTexture1);
};

void SceneGame2::Render(sf::RenderWindow* _window) {
	Scene::Render(_window);
}
