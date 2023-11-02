#pragma once

#include "Component.h"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics.hpp>

class Sprite : public Component
{
public:
	Sprite();
	~Sprite() override = default;

	void Update(sf::Time _delta);
	void SetTexture(const sf::Texture& _texture) { texture = _texture; }
	void SetScale(float _scalex, float _scaley) { scalex = _scalex; scaley = _scaley; }
	
	void LoadPlayAnimation();
	void PlayerPlayAnimation();
	

	void Render(sf::RenderWindow* _window) override;
	void SetRect(sf::IntRect* _rectSource) { rectTexture = _rectSource; }

private:
	sf::Texture texture;
	sf::IntRect* rectTexture;
	float scalex, scaley;
	std::vector<sf::Texture> anim;
	sf::Sprite sprite;
	int currentFrame;
	float frameDuration;
	sf::Clock animationClock;
};
