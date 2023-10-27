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
	Command* handleInput();
	void moveRight();
	void moveRightBullet();
	void moveLeft();
	void Gravity();
private:
	Command* KeyD_;
	Command* KeyQ_;
	Command* KeySpace_;
	
};

