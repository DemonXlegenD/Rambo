#pragma once
#include "SFML/Window/Event.hpp"
#include <iostream>

class Input
{
	static bool keyZ();
	static bool keyQ();
	static bool keyS();
	static bool keyD();
private:
	sf::Event event;
};

