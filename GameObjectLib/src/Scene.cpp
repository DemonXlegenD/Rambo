#include "Scene.h"
#include "Enemy/Grunt.h"

sf::RenderWindow* Scene::window = nullptr;

Scene::Scene(sf::RenderWindow* _window) {
	window = _window;
}

bool booll = false;


void Scene::Awake() {
	for (GameObject* const& gameObject : gameObjects)
	{
		gameObject->Start();
	}
}
void Scene::Update(sf::Time _delta)
{
	if (!booll)
	{
		sf::Texture ImageBongo;
		sf::Texture TextureGrunt;

		ImageBongo.loadFromFile("Sprite/player/john_static.png");

		TextureGrunt.loadFromFile("Sprite/player/john_static.png");

		GameObject* player = CreateCharacterGameObject("Player", 200.f, 400.f, ImageBongo, 2.5f, 2.5f);
		GameObject* grunt = CreateCharacterGameObject("Player", 200.f, 400.f, TextureGrunt, 2.5f, 2.5f);

		booll = true;
	}
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
	squareCollider->SetWidth(20.f);
	squareCollider->SetHeight(20.f);

	Sprite* sprite = gameObject->CreateComponent<Sprite>();
	sprite->SetTexture(texture);
	sprite->SetScale(scalex, scaley);

	CharacterControl* characterControl = gameObject->CreateComponent<CharacterControl>();

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

	Grunt* grunt = gameObject->CreateComponent<Grunt>();

	return gameObject;
}

GameObject* Scene::CreateButtonGameObject(const std::string& name, float x, float y, unsigned int fontSize)
{
	GameObject* gameObject = CreateGameObject(name);
	gameObject->SetPosition(Maths::Vector2f(x, y));

	Button* button = gameObject->CreateComponent<Button>();
	button->setPosition(x, y);
	button->setButton(fontSize);

	return gameObject;
}

GameObject* Scene::CreateButtonGameObject(const std::string& name,const sf::Texture texture, float x, float y, float scalex, float scaley) {
	
	GameObject* gameObject = CreateGameObject(name);
	gameObject->SetPosition(Maths::Vector2f(x, y));

	Button* button = gameObject->CreateComponent<Button>();
	button->setPosition(x, y);

	Sprite* sprite = gameObject->CreateComponent<Sprite>();
	sprite->SetTexture(texture);
	sprite->SetScale(scalex, scaley);

	return gameObject;

}
