#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Scene.h"

class Button : public Component
{

public:
	Button();

	void setButton(unsigned int fontSize);
	void setButton(const sf::Font& font, unsigned int fontSize);
	void setOrigin();
	void setSize(float _width, float _height);
	void setPosition(float _x, float _y);

	void Render(sf::RenderWindow* _window) override;
	bool isClicked(const sf::Vector2f& mousePosition);
	void Update(sf::Time _delta) override;

	~Button();

private:
	float width, height;
	sf::Font font;
	sf::RectangleShape rectangle;
	sf::Text text;
	sf::FloatRect textBounds;
	bool clicked = false;
};

