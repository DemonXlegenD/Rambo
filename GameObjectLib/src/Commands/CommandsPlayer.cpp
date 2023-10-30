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

void MoveToRightBulletCommand::Execute(sf::Time _delta) {
	Command::Execute(_delta);
	std::cout << "Delta = " << _delta.asSeconds() << std::endl;
	inputPlayer->MoveRightBullet();
}

GamePause::GamePause(InputPlayer* _inputPlayer) {
	this->inputPlayer = _inputPlayer;
}



void GamePause::Execute() {
	inputPlayer->GamePauseMenu();
}