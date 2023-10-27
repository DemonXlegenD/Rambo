#include "Scene.h"

#include "Components/Button.h"
#include "Components/SquareCollider.h"
#include "Components/FireBullet.h"
#include "Components/SpriteBullet.h"
#include "Components/SpriteRenderer.h"
#include "Components/Gravity.h"
#include "Components/Platforme.h"

sf::RenderWindow* Scene::window = nullptr;

Scene::Scene(sf::RenderWindow* _window) {
	Scene::setScene(this);
	window = _window;
	balleTiree = false;
	sf::Time interval = sf::seconds(0.5f);
}

Scene* Scene::scene = nullptr;

//bool booll = false;


void Scene::Awake() {
	for (GameObject* const& gameObject : gameObjects)
	{
		gameObject->Start();
	}
}
void Scene::Update(sf::Time _delta)
{
	sf::Event event;
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window->close();
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Escape) window->close();
		}

	}
	Command* commandMoves = inputHandlerPlayer->handleInput();
	if (commandMoves) {
		commandMoves->execute();
	}
	Command* fireBullet = inputHandlerPlayer->fireInput();
	if (fireBullet && !balleTiree) {
		fireBullet->execute();
		balleTiree = true;
		clock.restart();
	}
	if (clock.getElapsedTime() >= interval) {
		balleTiree = false; // Réinitialiser l'état de tir
	}
	//if (!booll)
	//{
	//	sf::Texture ImageBongo;
	//	sf::Texture TextureGrunt;

	//	ImageBongo.loadFromFile("Sprite/player/john_static.png");

	//	TextureGrunt.loadFromFile("Sprite/player/john_static.png");

	//	GameObject* player = CreateCharacterGameObject("Player", 200.f, 400.f, ImageBongo, 2.5f, 2.5f);
	//	GameObject* grunt = CreateCharacterGameObject("Player", 200.f, 400.f, TextureGrunt, 2.5f, 2.5f);

	//	booll = true;
	//}
	for (GameObject* const& gameObject : gameObjects)
	{
		gameObject->Update(_delta);
	}
}

void Scene::Render(sf::RenderWindow* _window)
{
	for (GameObject* const& gameObject : gameObjects)
	{
		gameObject->Render(_window);
	}
}

GameObject* Scene::CreateGameObject(const std::string& _name)
{
	auto gameObject = new GameObject();
	gameObject->SetName(_name);
	gameObjects.push_back(gameObject);
	return gameObject;
}

GameObject* Scene::CreateCharacterGameObject(const std::string& name, float positionx, float positiony, const sf::Texture texture, float scalex, float scaley)
{
	GameObject* gameObject = CreateGameObject(name);
	gameObject->SetPosition(Maths::Vector2f(positionx, positiony));

	SquareCollider* squareCollider = gameObject->CreateComponent<SquareCollider>();
	squareCollider->SetWidth(60.f);
	squareCollider->SetHeight(60.f);

	Sprite* sprite = gameObject->CreateComponent<Sprite>();
	sprite->SetTexture(texture);
	sprite->SetScale(scalex, scaley);
	
	Gravity* gravity = gameObject->CreateComponent<Gravity>();


	InputPlayer* inputPlayer = gameObject->CreateComponent<InputPlayer>();
	inputHandlerPlayer = inputPlayer;
	return gameObject;
}

GameObject* Scene::CreateGruntGameObject(const std::string& _name)
{
	auto gameObject = new GameObject();
	gameObject->SetName(_name);
	gameObjectsGrunt.push_back(gameObject);
	return gameObject;
}

GameObject* Scene::CreateGruntGameObject(const std::string& name, float position, const sf::Texture texture, float scalex, float scaley)
{
	GameObject* gameObject = CreateGruntGameObject(name);
	gameObject->SetPosition(Maths::Vector2f(position, position));

	SquareCollider* squareCollider = gameObject->CreateComponent<SquareCollider>();
	squareCollider->SetWidth(20.f);
	squareCollider->SetHeight(20.f);

	Sprite* sprite = gameObject->CreateComponent<Sprite>();
	sprite->SetTexture(texture);
	sprite->SetScale(scalex, scaley);

	//Grunt* grunt = gameObject->CreateComponent<Grunt>();

	return gameObject;
}

GameObject* Scene::CreateButtonGameObject(const std::string& name, float x, float y, unsigned int fontSize)
{
	GameObject* gameObject = CreateGameObject(name);
	gameObject->SetPosition(Maths::Vector2f(x, y));

	Button* button = gameObject->CreateComponent<Button>();
	button->setPosition(x, y);
	button->setButton(fontSize);
	button->setOrigin();

	return gameObject;
}


GameObject* Scene::CreatePlatformObject(const std::string& name, float x, float y, float scaleX, float scaleY) {

	GameObject* gameObject = CreateGameObject(name);
	gameObject->SetPosition(Maths::Vector2f(x, y));

	SquareCollider* squareCollider = gameObject->CreateComponent<SquareCollider>();
	squareCollider->SetWidth(scaleX);
	squareCollider->SetHeight(scaleY);

	Platforme* platform = gameObject->CreateComponent<Platforme>();
	platform->setPosition(x, y);
	platform->setPlatforme();
	platform->setSize(scaleX, scaleY);

	return gameObject;
}
GameObject* Scene::CreateBulletGameObject(const std::string& name, const sf::Texture textureBullet, float scalex, float scaley, GameObject* _player)
{
	GameObject* gameObject = CreateGameObject(name);
	gameObject->SetPosition(Maths::Vector2f(_player->GetPosition().GetX(), _player->GetPosition().GetY()));

	SpriteBullet* spriteBullet = gameObject->CreateComponent<SpriteBullet>();
	spriteBullet->SetTexture(textureBullet);
	spriteBullet->SetScale(scalex, scaley);

	FireBullet* fireBullet = gameObject->CreateComponent<FireBullet>();


	return gameObject;

}