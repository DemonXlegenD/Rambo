#pragma once

#include "Component.h"
#include <SFML/Graphics/Texture.hpp>

class Sprite : public Component
{
public:
	Sprite();
	~Sprite() override = default;

	void SetTexture(const sf::Texture& _texture) { texture = _texture; }
	void SetScale(float _scalex, float _scaley) { scalex = _scalex; scaley = _scaley;}

	void Render(sf::RenderWindow* _window) override;
	void SetRect(sf::IntRect* _rectSource) { rectTexture = _rectSource; }

private:
	sf::Texture texture;
	sf::IntRect* rectTexture;
	float scalex, scaley;
};
