#include "Commands/CommandsPlayer.h"

MoveToRightCommand::MoveToRightCommand(InputPlayer* _inputPlayer) {
	this->inputPlayer = _inputPlayer;
}
void MoveToRightCommand::execute() {
	inputPlayer->moveRight();
}

MoveToLeftCommand::MoveToLeftCommand(InputPlayer* _inputPlayer) {
	this->inputPlayer = _inputPlayer;
}

void MoveToLeftCommand::execute() {
	inputPlayer->moveLeft();
}