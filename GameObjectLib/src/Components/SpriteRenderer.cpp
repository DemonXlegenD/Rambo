#include "Components/SpriteRenderer.h"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/Sprite.hpp"

Sprite::Sprite()
{
	texture.create(0, 0);
}

Sprite::~Sprite() {}

void Sprite::Render(sf::RenderWindow* _window)
{
	Component::Render(_window);

	const auto position = GetOwner()->GetPosition();
	sf::Sprite sprite(texture);
	sprite.setPosition(position.x, position.y);
	sprite.setTexture(texture);
	sprite.setScale(scalex, scaley);

	_window->draw(sprite);
}