#pragma once
#include "Components/Inputs/InputPlayer.h"

class InputPlayer;

class MoveToRightCommand : public Command
{
public:
	MoveToRightCommand(InputPlayer* _inputPlayer);
	void Execute() override;
	InputPlayer* inputPlayer;
};

class MoveToLeftCommand : public Command
{
public:
	MoveToLeftCommand(InputPlayer* _inputPlayer);
	void Execute() override;
	InputPlayer* inputPlayer;
};

class MoveToRightBulletCommand : public Command
{
public:
	MoveToRightBulletCommand(InputPlayer* _inputPlayer);
	void Execute() override;
	InputPlayer* inputPlayer;
};
