#include "Scene.h"

sf::RenderWindow* Scene::window = nullptr;

Scene::Scene(sf::RenderWindow* _window) {
	window = _window;
}

void Scene::Update(sf::Time _delta)
{
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

GameObject* Scene::CreateCharacterGameObject(const std::string& name, float position, const sf::Texture texture, float scalex, float scaley)
{
	GameObject* gameObject = CreateGameObject(name);
	gameObject->SetPosition(Maths::Vector2f(position, position));

	SquareCollider* squareCollider = gameObject->CreateComponent<SquareCollider>();
	squareCollider->SetWidth(20.f);
	squareCollider->SetHeight(20.f);

	Sprite* sprite = gameObject->CreateComponent<Sprite>();
	sprite->SetTexture(texture);
	sprite->SetScale(scalex, scaley);

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
