#include "Components/inputPlayer.h"


InputPlayer::InputPlayer() {
	KeyD_ = new MoveToRightCommand(this);
	KeyQ_ = new MoveToLeftCommand(this);
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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) return KeyQ_;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) return KeyD_;

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

