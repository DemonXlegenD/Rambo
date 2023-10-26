#include "Components/Button.h"


Button::Button() {
	this->height = 0;
	this->width = 0;
	this->clicked = false;
	this->window = Scene::GetWindow();
}


void Button::setButton(unsigned int fontSize) {
	

	if (!font.loadFromFile("../Fonts/Roboto-Medium.ttf")) {
		std::cout << "Font introuvable" << std::endl;
	}
	text = sf::Text(GetOwner()->GetName(), font, fontSize);
	text.setFillColor(sf::Color::White);

	textBounds = text.getLocalBounds();
	this->setSize(textBounds.width + fontSize *3, textBounds.height + fontSize * 1.5);
	
	rectangle = sf::RectangleShape(sf::Vector2f(width, height));
	rectangle.setOutlineThickness(2);
	rectangle.setOutlineColor(sf::Color::White);
	rectangle.setFillColor(sf::Color::Blue);
}

void Button::setButton(const sf::Font& font, unsigned int fontSize) {
	text = sf::Text(GetOwner()->GetName(), font, fontSize);
	text.setFillColor(sf::Color::White);

	textBounds = text.getLocalBounds();
	this->setSize(textBounds.width + fontSize * 3, textBounds.height + fontSize * 1.5);

	rectangle.setSize(sf::Vector2f(width, height));
	rectangle.setFillColor(sf::Color::Blue);
}

void Button::setOrigin() {
	rectangle.setOrigin(sf::Vector2f(width / 2, height / 2));
	text.setOrigin(sf::Vector2f(textBounds.width / 2, textBounds.height / 2));
}

void Button::setSize(float _width, float _height) {
	width = _width;
	height = _height;
}

void Button::setPosition(float _x, float _y) {
	text.setPosition(_x, _y);
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
	/*sf::Event event;
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::MouseButtonPressed) {
			std::cout << this->isClicked(sf::Vector2f(sf::Mouse::getPosition(*window))) << std::endl;
			if (this->isClicked(sf::Vector2f(sf::Mouse::getPosition(*window)))) {
				clicked = true;
				std::cout << GetOwner()->GetName() << " noob" << std::endl;
			}

		}
	}*/
}

bool Button::isClicked(const sf::Vector2f& mousePosition) {
	return rectangle.getGlobalBounds().contains(mousePosition) && sf::Mouse::isButtonPressed(sf::Mouse::Left) && !clicked;
}


Button::~Button() {}