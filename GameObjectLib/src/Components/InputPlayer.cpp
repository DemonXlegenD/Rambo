#include "Components/inputPlayer.h"
#include "Scenes/SceneMainMenu.h"


InputPlayer::InputPlayer() {
	KeyD_ = new MoveToRightCommand(this);
	KeyQ_ = new MoveToLeftCommand(this);
	KeySpace_ = new MoveToRightBulletCommand(this);
}


Command* InputPlayer::handleInput() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) return KeyQ_;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) return KeyD_;

	return nullptr;

}

Command* InputPlayer::fireInput() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) return KeySpace_;
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

void InputPlayer::moveRightBullet()
{
	sf::Texture* texture = new sf::Texture();
	if (!texture->loadFromFile("../assets/Sprite/player/weaponBullet/weapon_bullet_0.png")) {
		std::cout << "pas d'image" << std::endl;
	}

	Scene::getScene()->CreateBulletGameObject("Bullet", *texture, 2.5f, 2.5f, GetOwner());
}
