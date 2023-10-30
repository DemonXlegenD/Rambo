#pragma once
#include "SFML/Window/Event.hpp"

#include "Command.h"
#include "Components/Component.h"
#include "Commands/CommandsPlayer.h"
#include <functional>

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
	Command* KeyEscape_;
	

};

