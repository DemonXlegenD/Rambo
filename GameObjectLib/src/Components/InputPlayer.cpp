#include "Components/inputPlayer.h"
#include "Scene.h"

InputPlayer::InputPlayer(){}
void InputPlayer::Update(sf::Time _delta)
{
}

void InputPlayer::moveRight(GameObject* player, sf::Time _delta)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		player->SetPosition(player->GetPosition() + Maths::Vector2f::Right);
	};
}

void InputPlayer::moveLeft(GameObject* player, sf::Time _delta)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		player->SetPosition(player->GetPosition() + Maths::Vector2f::Left);
	};
}



