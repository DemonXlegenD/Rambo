#pragma once

#include <SFML/Graphics/Texture.hpp>
#include "Component.h"

class Sprite : public Component
{
public:
	Sprite();
	~Sprite() override;

	void SetTexture(const sf::Texture& _texture) { texture = _texture; }
	void SetScale(float _scalex, float _scaley) { scalex = _scalex; scaley = _scaley;}

	void Render(sf::RenderWindow* _window) override;

private:
	sf::Texture texture;
	float scalex;
	float scaley;
};
