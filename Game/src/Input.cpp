#include "Input.h"

bool Input::keyZ()
{
	std::cout << "Z" << std::endl;
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Z);
}

bool Input::keyQ()
{
	std::cout << "Q" << std::endl;
	return sf::Keyboard::isKeyPressed(sf::Keyboard::Q);
}

bool Input::keyS()
{
	std::cout << "S" << std::endl;
	return sf::Keyboard::isKeyPressed(sf::Keyboard::S);
}

bool Input::keyD()
{
	std::cout << "D" << std::endl;
	return sf::Keyboard::isKeyPressed(sf::Keyboard::D);
}