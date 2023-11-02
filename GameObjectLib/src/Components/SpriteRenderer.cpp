#include "Components/SpriteRenderer.h"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/Sprite.hpp"

Sprite::Sprite()
{
	texture.create(100, 100);
	scalex = 1.0f;
	scaley = 1.0f;
	rectTexture = nullptr;
}



void Sprite::Render(sf::RenderWindow* _window)
{
	Component::Render(_window);

	const auto position = GetOwner()->GetPosition();
	sf::Sprite sprite(texture);
	sprite.setPosition(position.x, position.y);
	if (this->rectTexture) {
		sprite.setTextureRect(*rectTexture);
	}
	else {
		sprite.setTexture(texture);
	}

	
	sprite.setScale(scalex, scaley);

	_window->draw(sprite);
}
