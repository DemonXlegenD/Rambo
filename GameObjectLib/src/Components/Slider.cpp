#include "Components/Slider.h"
#include "SceneManager.h"

Slider::Slider() {
	bar.setFillColor(sf::Color::Green);
	text.setFillColor(sf::Color::White);
	cursor.setFillColor(sf::Color(0, 100, 0));
	cursor.setOutlineThickness(3);
	cursor.setOutlineColor(sf::Color::White);
	percent = 0.f;
}

void Slider::SetSizeBar(float _width, float _height)
{
	bar.setSize(sf::Vector2f(_width, _height));
	bar.setOrigin(sf::Vector2f(_width / 2, _height / 2));
}

void Slider::SetSizeCursor(float _width, float _height)
{
	cursor.setSize(sf::Vector2f(_width, _height));
	cursor.setOrigin(sf::Vector2f(_width / 2, _height / 2));
}

void Slider::SetText(unsigned int _fontSize) {
	fontSize = _fontSize;
	if (!font.loadFromFile("../Fonts/Roboto-Medium.ttf")) {
		std::cout << "no font found" << std::endl;
	}
	text = sf::Text(std::to_string(data), font, fontSize);
	text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2);
}

void Slider::SetText(unsigned int _fontSize, float _data) {
	data = _data;
	fontSize = _fontSize;
	if (!font.loadFromFile("../Fonts/Roboto-Medium.ttf")) {
		std::cout << "no font found" << std::endl;
	}
	text = sf::Text(std::to_string(data), font, fontSize);
	text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2);
}

void Slider::SetPosition(float _x, float _y)
{
	bar.setPosition(sf::Vector2f(_x, _y));
	cursor.setPosition(sf::Vector2f(_x + bar.getSize().x / 2, _y));
	text.setPosition(sf::Vector2f(_x + bar.getSize().x / 2, _y));
	
}

void Slider::Render(sf::RenderWindow* _window) {
	Component::Render(_window);

	_window->draw(bar);
	_window->draw(cursor);
	_window->draw(text);
}
float Slider::GetPercent(float _x, float _y, float width) {
	if (width == 0.0) {
		return 0.0; 
	}

	float pourcentage = ((_y - (_x - width / 2)) / width) * 100.0;

	// Assurez-vous que le pourcentage reste entre 0 et 100
	pourcentage = std::fmax(0.0, std::fmin(100.0, pourcentage));

	return pourcentage;
}


void Slider::Update(sf::Time _delta) {
	Component::Update(_delta);
	sf::Vector2i mousePos = sf::Mouse::getPosition(*SceneManager::GetWindow());
	if (this->isClicked(mousePos)) {
		float cursorX = static_cast<float>(mousePos.x) - cursor.getSize().x / 2;
		if (cursorX < (bar.getPosition().x - bar.getSize().x / 2))
			cursorX = (bar.getPosition().x - bar.getSize().x / 2);
		else if (cursorX > bar.getPosition().x + bar.getSize().x / 2 - cursor.getSize().x / 2) {
			cursorX = bar.getPosition().x + bar.getSize().x / 2 - cursor.getSize().x / 2;
		}

		cursor.setPosition(cursorX + cursor.getSize().x / 2, cursor.getPosition().y);
		percent = this->GetPercent(bar.getPosition().x, cursor.getPosition().x, bar.getSize().x);
		this->SetData(data * percent / 100);
		this->SetText(fontSize);
		text.setPosition(cursorX + cursor.getSize().x / 2, text.getPosition().y);
	}
}

bool Slider::isClicked(sf::Vector2i _mousePosition) {
	return cursor.getGlobalBounds().contains(sf::Vector2f(_mousePosition.x, _mousePosition.y)) && sf::Mouse::isButtonPressed(sf::Mouse::Left);
}