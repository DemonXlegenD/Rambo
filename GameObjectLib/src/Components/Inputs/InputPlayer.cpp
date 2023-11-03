#include "Components/Inputs/InputPlayer.h"
#include "Commands/CommandsPlayer.h"
#include "Components/Armes.h"
#include "SceneManager.h"

InputPlayer::InputPlayer() {
	KeyD_ = new MoveToRightCommand(this);
	KeyQ_ = new MoveToLeftCommand(this);
	KeySpace_ = new MoveToRightBulletCommand(this);
	KeyEscape_ = new GamePause(this);
}


Command* InputPlayer::HandleInput() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) return KeyQ_;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) return KeyD_;

	return nullptr;

}

Command* InputPlayer::FireInput() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) return KeySpace_;
	return nullptr;
}

Command* InputPlayer::PauseInput() {
	static bool isPressedEscape = false;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && !isPressedEscape) {
		isPressedEscape = true;
		return KeyEscape_;
	}

	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		isPressedEscape = false;
	}

	return nullptr;
}


void InputPlayer::MoveRight()
{

	GetOwner()->SetPosition(GetOwner()->GetPosition() + Maths::Vector2f::Right + Maths::Vector2f(3, 0) /* La faut mettre le delta time et c'est bon*/);
	GetOwner()->GetComponent<Player>()->setDirection(Player::Direction::Right);
	GetOwner()->GetComponent<Sprite>()->PlayerPlayAnimationRun();
}

void InputPlayer::MoveLeft()
{
	GetOwner()->SetPosition(GetOwner()->GetPosition() + Maths::Vector2f::Left + Maths::Vector2f(-3, 0));
	GetOwner()->GetComponent<Player>()->setDirection(Player::Direction::Left);
	GetOwner()->GetComponent<Sprite>()->PlayerPlayAnimationRun();
}

void InputPlayer::MoveRightBullet()
{
	player = SceneManager::GetActiveScene()->getGameObject("Player");
	player->GetComponent<Armes>()->Shoot();
}

void InputPlayer::GamePauseMenu()
{
}
