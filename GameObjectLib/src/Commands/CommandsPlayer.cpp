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

MoveToRightBulletCommand::MoveToRightBulletCommand(InputPlayer* _inputPlayer) {
	this->inputPlayer = _inputPlayer;
}

void MoveToRightBulletCommand::execute() {
	inputPlayer->moveRightBullet();
}