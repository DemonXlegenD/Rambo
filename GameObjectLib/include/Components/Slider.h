#pragma once
#include "Component.h"
#include <SFML/Graphics.hpp>


class Slider : public Component
{
public:
	Slider();

	void SetSizeBar(float _width, float _height);
	void SetSizeCursor(float _width, float _height);
	void SetPosition(float _x, float _y);
	void SetText(unsigned int _fontSize);
	void SetText(unsigned int _fontSize, float _data);

	void Render(sf::RenderWindow* _window) override;
	void Update(sf::Time _delta) override;
	bool isClicked(sf::Vector2i _mousePosition);

	float GetPercent(float _x, float _y, float width);

	int GetDataInt() { return (int)data; }
	float GetDataFloat() { return data; }
	void SetData(float _data) { data = _data; }
	
private:
	sf::RectangleShape bar;
	sf::RectangleShape cursor;
	sf::Text text;
	sf::Font font;
	unsigned int fontSize;
	float data;
	float percent;
};

