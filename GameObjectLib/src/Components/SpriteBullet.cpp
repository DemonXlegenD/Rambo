#include "Components/SpriteBullet.h"
#include "SFML/Graphics/Sprite.hpp"

SpriteBullet::SpriteBullet()
{
	texture.create(100, 100);
	scalex = 1.0f;
	scaley = 1.0f;
}

SpriteBullet::~SpriteBullet() {}

void SpriteBullet::Render(sf::RenderWindow* _window)
{
	Component::Render(_window);

	const auto position = GetOwner()->GetPosition();
	sf::Sprite sprite(texture);
	sprite.setPosition(position.x, position.y);
	sprite.setTexture(texture);
	sprite.setScale(scalex, scaley);

	_window->draw(sprite);
}