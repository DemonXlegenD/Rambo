#pragma once
#include "SFML/Window/Event.hpp"
#include "Component.h"

class InputPlayer : public Component
{
public:
	InputPlayer();
	void Update(sf::Time _delta) override;
	void moveRight(GameObject* player, sf::Time _delta);
	void moveLeft(GameObject* player, sf::Time _delta);

};

