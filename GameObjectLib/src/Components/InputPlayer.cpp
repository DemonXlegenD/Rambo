#include "Components/inputPlayer.h"


InputPlayer::InputPlayer() {
	KeyD_ = new MoveToLeftCommand(this);
	KeyQ_ = new MoveToRightCommand(this);
}
//void InputPlayer::Update(sf::Time _delta)
//{
//	/*Gravity(GetOwner());
//	sf::Event event;
//	while (Scene::GetWindow()->pollEvent(event))
//	{
//		moveRight(GetOwner(), _delta);
//		moveLeft(GetOwner(), _delta);
//		
//	}*/
//}

Command* InputPlayer::handleInput() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) return KeyQ_;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) return KeyD_;

	return nullptr;
}

void InputPlayer::moveRight()
{
	GetOwner()->SetPosition(GetOwner()->GetPosition() + Maths::Vector2f::Right);
}

void InputPlayer::moveLeft()
{
	GetOwner()->SetPosition(GetOwner()->GetPosition() + Maths::Vector2f::Left);
}

void InputPlayer::Gravity() 
{
	GetOwner()->SetPosition(GetOwner()->GetPosition() + Maths::Vector2f::Up);

}

