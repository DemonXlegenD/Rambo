#pragma once
#include "SFML/Window/Event.hpp"
#include "Command.h"
#include "Component.h"
#include "Commands/CommandsPlayer.h"

class InputPlayer : public Component
{
public:
	InputPlayer();
	Command* handleInput();
	void moveRight();
	void moveLeft();
	void Gravity();
private:
	Command* KeyD_;
	Command* KeyQ_;
};

