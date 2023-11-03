#include "Scenes/SceneGame2.h"
#include "SceneManager.h"
#include "Components/SpriteRenderer.h"
#include "Components/SquareCollider.h"
#include "Components/Gravity.h"
#include "AssetManager.h"
#include "Components/SpriteRenderer.h"
#include "Components/Button.h"
#include "Scenes/SceneMainMenu.h"

SceneGame2::SceneGame2(sf::RenderWindow* _window) : SceneGameAbstract(_window) {
	srand(time(nullptr));
	this->Awake();
	Scene::Create();
}

bool SceneGame2::PauseMenu(bool gamePause)
{
	return gamePause;
};

void SceneGame2::Create() {
	SceneGameAbstract::Create();
	this->CreatePlayer();
	CreatePlatform(sf::Texture());
	for (size_t i = 0; i < 9; i++) {
		this->CreateGrunt();
	}
	
	this->CreateTurret(sf::Texture());
	
}

void SceneGame2::Awake() {
	SceneGameAbstract::Awake();
}



void SceneGame2::CreateTurret(sf::Texture imageTurret)
{
	if (!imageTurret.loadFromFile("../assets/Sprite/enemy/turret/turret_0.png"))
	{
		std::cout << "pas d'image ennemy" << std::endl;
	}


	this->turret1 = CreateGruntGameObject("Turret1", 100.f, 100.f, 2.5f, 2.5f, imageTurret);
	this->turret2 = CreateGruntGameObject("Turret2", 1800.f, 100.f, 2.5f, 2.5f, imageTurret);

	this->turret1->GetComponent<Gravity>()->Stop();
	this->turret2->GetComponent<Gravity>()->Stop();
}




void SceneGame2::Update(sf::Time _delta) {

	SceneGameAbstract::Update(_delta);
}

void SceneGame2::CreatePlatform(sf::Texture textureplatforme) {


	if (!textureplatforme.loadFromFile("../assets/Sprite/tiles_spritesheet.png"))
	{
		std::cout << "pas d'image ennemy" << std::endl;
	}

	sf::IntRect rectSource(200, 0, 95, 40);
	platforms.push_back(CreatePlatformObject("platforme1", 300.f, 650.f, 3.75f, 2.f, textureplatforme, new sf::IntRect(rectSource)));
	platforms.push_back(CreatePlatformObject("platforme2", 800.f, 500.f, 3.75f, 2.f, textureplatforme, new sf::IntRect(rectSource)));
	platforms.push_back(CreatePlatformObject("platforme3", 1100.f, 500.f, 3.75f, 2.f, textureplatforme, new sf::IntRect(rectSource)));
	platforms.push_back(CreatePlatformObject("platforme4", 1600.f, 650.f, 4.f, 2.f, textureplatforme, new sf::IntRect(rectSource)));
	platforms.push_back(CreatePlatformObject("platforme5", 800.f, 800.f, 3.75f, 2.f, textureplatforme, new sf::IntRect(rectSource)));
	platforms.push_back(CreatePlatformObject("platforme6", 1100.f, 800.f, 3.75f, 2.f, textureplatforme, new sf::IntRect(rectSource)));
}


void SceneGame2::Render(sf::RenderWindow* _window) {
	SceneGameAbstract::Render(_window);
}
