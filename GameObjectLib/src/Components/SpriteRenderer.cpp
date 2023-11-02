#include "Components/SpriteRenderer.h"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "AssetManager.h"

Sprite::Sprite()
{

	texture.create(100, 100);
	scalex = 1.0f;
	scaley = 1.0f;
	rectTexture = nullptr;

    currentFrame = 0;
    frameDuration = 0.2f;
    animationClock.restart();
    LoadPlayAnimation();

}

void Sprite::LoadPlayAnimation()
{
    for (int i = 0; i <= 4; i++) {
        std::string filename = "../assets/Sprite/player/playerStatic/john_idle_" + std::to_string(i) + ".png";

        AssetManager::AddAsset("Player" + std::to_string(i), sf::Texture());
        AssetManager::LoadAsset("Player" + std::to_string(i), filename);
        anim.push_back(AssetManager::GetAsset("Player" + std::to_string(i)));
    }
}

void Sprite::PlayerPlayAnimation()
{
    if (animationClock.getElapsedTime().asSeconds() > frameDuration)
    {
        currentFrame = (currentFrame + 1) % anim.size();
        texture = anim[currentFrame];
        animationClock.restart();
    }
}

void Sprite::Update(sf::Time _delta)
{    
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
