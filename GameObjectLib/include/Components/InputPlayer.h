#pragma once
#include "SFML/Window/Event.hpp"
#include "../Game/include/Input.h"
#include "Scene.h"
#include "Maths/Vector2.h"

class InputPlayer : public Component
{
public:
	void Update(sf::Time _delta) override;
	void moveRight(GameObject* player, sf::Time _delta);
	void moveLeft(GameObject* player, sf::Time _delta);
	void Gravity(GameObject* player);

};

