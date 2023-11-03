#pragma once

#include "Command.h"
#include "Components/Component.h"


class InputPlayer : public Component
{
public:
	InputPlayer();


	Command* HandleInput();
	Command* FireInput();
	Command* PauseInput();
	void MoveRight();
	void MoveRightBullet();
	void GamePauseMenu();
	void MoveLeft();

private:
	Command* KeyD_;
	Command* KeyQ_;
	Command* KeySpace_;
	GameObject* player;
	Command* KeyEscape_;
};

