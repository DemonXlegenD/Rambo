#pragma once
#include "GameObject.h"
#include <SFML/Graphics/Texture.hpp>

class SpriteBullet : public Component
{
public:
	SpriteBullet();
	~SpriteBullet() override;

	void SetTexture(const sf::Texture& _texture) { texture = _texture; }
	void SetScale(float _scalex, float _scaley) { scalex = _scalex; scaley = _scaley; }

	void Render(sf::RenderWindow* _window) override;

private:
	sf::Texture texture;
	float scalex, scaley;
};
