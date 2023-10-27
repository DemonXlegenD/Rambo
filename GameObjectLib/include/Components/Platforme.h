#pragma once
#include <SFML/Graphics.hpp>
#include "Component.h"

class Platforme : public Component
{
public:
	Platforme();
	void setPlatforme();
	void setOrigin();
	void setSize(float _width, float _height);
	void setPosition(float _x, float _y);
	void Render(sf::RenderWindow* _window) override;

private:
	float width, height, scaleX, scaleY;
	sf::RectangleShape rectangle;
	sf::RenderWindow* window = nullptr;
};

