#include "Components/Platforme.h"

Platforme::Platforme() {
	this->height = 0;
	this->width = 0;
	this->scaleX = 0;
	this->scaleY = 0;
};
void Platforme::setPlatforme() {

	rectangle = sf::RectangleShape(sf::Vector2f(width, height));
	rectangle.setFillColor(sf::Color::Blue);
}

void Platforme::setOrigin() {
	rectangle.setOrigin(sf::Vector2f(width / 2, height / 2));
}

void Platforme::setSize(float scaleX, float scaleY) {
	rectangle.setSize(sf::Vector2f(scaleX, scaleY));
}

void Platforme::setPosition(float _x, float _y) {
	rectangle.setPosition(_x, _y);
}

void Platforme::Render(sf::RenderWindow* _window) {
	Component::Render(_window);

	const auto position = GetOwner()->GetPosition();
	setPosition(position.x, position.y);
	_window->draw(rectangle);
}