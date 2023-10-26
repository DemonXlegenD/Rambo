#pragma once

#include "Component.h"
#include "Maths/Vector2.h"
#include "SFML/Window/Event.hpp"

class CharacterControl : public Component
{
public:

	void Update(sf::Time _delta) override;
};
