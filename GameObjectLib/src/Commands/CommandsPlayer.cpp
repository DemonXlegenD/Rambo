#include "Commands/CommandsPlayer.h"

MoveToRightCommand::MoveToRightCommand(InputPlayer* _inputPlayer) {
	this->inputPlayer = _inputPlayer;
}
void MoveToRightCommand::Execute() {
	inputPlayer->MoveRight();
}

MoveToLeftCommand::MoveToLeftCommand(InputPlayer* _inputPlayer) {
	this->inputPlayer = _inputPlayer;
}

void MoveToLeftCommand::Execute() {
	inputPlayer->MoveLeft();
}

MoveToRightBulletCommand::MoveToRightBulletCommand(InputPlayer* _inputPlayer) {
	this->inputPlayer = _inputPlayer;
}

void MoveToRightBulletCommand::Execute() {
	inputPlayer->MoveRightBullet();
}

GamePause::GamePause(InputPlayer* _inputPlayer) {
	this->inputPlayer = _inputPlayer;
}

void GamePause::Execute() {
	inputPlayer->GamePauseMenu();
}