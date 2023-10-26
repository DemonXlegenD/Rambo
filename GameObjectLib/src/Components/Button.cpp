#include "Components/Button.h"


Button::Button() {
	this->height = 0;
	this->width = 0;
	this->clicked = false;

}


void Button::setButton(unsigned int fontSize) {

	if (!font.loadFromFile("../Fonts/Roboto-Medium.ttf")) {
		std::cout << "Font introuvable" << std::endl;
	}
	text = sf::Text(GetOwner()->GetName(), font, fontSize);
	text.setFillColor(sf::Color::White);

	sf::FloatRect textBounds = text.getLocalBounds();
	setSize(textBounds.width + 20, textBounds.height + 20);

	rectangle = sf::RectangleShape(sf::Vector2f(width, height));
	rectangle.setFillColor(sf::Color::Blue);
}

void Button::setButton(const sf::Font& font, unsigned int fontSize) {
	text = sf::Text(GetOwner()->GetName(), font, fontSize);
	text.setFillColor(sf::Color::White);

	sf::FloatRect textBounds = text.getLocalBounds();
	setSize(textBounds.width + 20, textBounds.height + 20);

	rectangle.setSize(sf::Vector2f(width, height));
	rectangle.setFillColor(sf::Color::Blue);
}

void Button::setSize(float _width, float _height) {
	width = _width;
	height = _height;
}

void Button::setPosition(float _x, float _y) {
	text.setPosition(_x + 10, _y + 10);
	rectangle.setPosition(_x, _y);
}

void Button::Render(sf::RenderWindow* _window) {
	Component::Render(_window);

	const auto position = GetOwner()->GetPosition();
	setPosition(position.x, position.y);
	_window->draw(rectangle);
	_window->draw(text);
}

void Button::Update(sf::Time _delta) {
}

bool Button::isClicked(const sf::Vector2f& mousePosition) {
	return rectangle.getGlobalBounds().contains(mousePosition);
}


Button::~Button() {}