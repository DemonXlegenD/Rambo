#pragma once

#include "Command.h"
#include "Components/Component.h"


class InputPlayer : public Component
{
public:
	InputPlayer();

	Command* HandleInput();
	Command* FireInput();
	void MoveRight();
	void MoveRightBullet();
	void MoveLeft();

private:
	Command* KeyD_;
	Command* KeyQ_;
	Command* KeySpace_;
	GameObject* player;

};

