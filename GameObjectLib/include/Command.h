#pragma once

#include <SFML/Graphics.hpp>
class Command
{
public:
	~Command();
	virtual void Execute() = 0;
	virtual void Execute(sf::Time delta);
};

