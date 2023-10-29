#pragma once
#include "SFML/Window/Event.hpp"

#include "Command.h"
#include "Component.h"
#include "Commands/CommandsPlayer.h"
#include <functional>

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
	

};

