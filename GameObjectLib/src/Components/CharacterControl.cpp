#include "Components/CharacterControl.h"

GameObject player;

void CharacterControl::Update(sf::Time _delta)
{
	sf::Event event{};
	Component::Update(_delta);

	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::D)
		{
			std::cout << "bongo" << std::endl;
			for (int i = 0; i < 10; i++)
			{
				player.SetPosition(player.GetPosition() + Maths::Vector2f::Right);
			}
			player.SetPosition(Maths::Vector2f(10.0f, 10.0f));
		}
	}
}