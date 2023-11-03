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

	sf::Vector2f GetBounds() { return sf::Vector2f(sprite.getLocalBounds().width, sprite.getLocalBounds().height); }
	
	void LoadPlayAnimation();
	void PlayerPlayAnimation();
	void PlayerPlayAnimationRun();
	void LoadPlayAnimationGrunt();
	void GruntPlayAnimation();
	void GruntPlayAnimationRun();
	

	void Render(sf::RenderWindow* _window) override;
	void SetRect(sf::IntRect* _rectSource) { rectTexture = _rectSource; }

private:
	sf::Texture texture;
	sf::IntRect* rectTexture;
	float scalex, scaley;
	std::vector<sf::Texture> animPlayer;
	std::vector<sf::Texture> animPlayerRun;
	std::vector<sf::Texture> animGrunt;
	std::vector<sf::Texture> animGruntRun;
	sf::Sprite sprite;
	int currentFrame;
	float frameDuration;
	sf::Clock animationClock;
};
