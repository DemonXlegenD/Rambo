#include "Components/Atout.h"
#include "Components/Button.h"

Atout::Atout() {
	speed = false;
	damage = false;
	health = false;
};
//void Atout::Create() {
//	sf::Texture backgroundTexture1;
//	sf::Texture backgroundTexture2;
//	if (!backgroundTexture1.loadFromFile("../assets/Sprite/background/background_color.png"))
//	{
//		std::cout << "pas d'image" << std::endl;
//	}
//	if (!backgroundTexture2.loadFromFile("../assets/Sprite/background/jungle_bg_trees.png"))
//	{
//		std::cout << "pas d'image" << std::endl;
//	}
//
//	GameObject* background1 = CreateBackgroundGameObject("Background1", SceneManager::GetWindowWidth() / 2, SceneManager::GetWindowHeight() / 2, backgroundTexture1);
//	GameObject* background2 = CreateBackgroundGameObject("Background2", SceneManager::GetWindowWidth() / 2, SceneManager::GetWindowHeight() / 2, backgroundTexture2);
//	this->CreateSceneButtonsMenu();
//
//}

void Atout::Render(sf::RenderWindow* _window) {
	GetOwner()->GetComponent<Scene>()->Render(_window);
}

void Atout::CreateButtonAdd() {
	float widthScreen = SceneManager::GetWindow()->getSize().x;
	float heightScreen = SceneManager::GetWindow()->getSize().y;
	addSpeed = GetOwner()->GetComponent<Scene>()->CreateButtonGameObject("Speed", widthScreen / 2, heightScreen / 3, 50);
	addDamamge = GetOwner()->GetComponent<Scene>()->CreateButtonGameObject("Damage", widthScreen / 2, heightScreen / 2, 20);
	addHealt = GetOwner()->GetComponent<Scene>()->CreateButtonGameObject("Healt", widthScreen / 2, heightScreen / 1.5, 50);
}

void Atout::Update(sf::Time _delta) {
	GetOwner()->GetComponent<Scene>()->Update(_delta);
	if (addSpeed->GetComponent<Button>()->IsClicked() && addSpeed->GetActive() && !speed) {
		atouts.push_back(addSpeed);
		speed = true;
	}
	if (addDamamge->GetComponent<Button>()->IsClicked() && addDamamge->GetActive() && !damage) {
		atouts.push_back(addDamamge);
		damage = true;
	}
	if (addHealt->GetComponent<Button>()->IsClicked() && addHealt->GetActive() && !health) {
		atouts.push_back(addHealt);
		health = true;
	}
}
