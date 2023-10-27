#include "Components/Gravity.h"

Gravity::Gravity() {
	this->start();
}
void Gravity::Update(sf::Time _delta) {
	if (isPlaying) {
		this->gravity();
	}
}

void Gravity::stop() {
	this->isPlaying = false;
}

void Gravity::start() {
	this->isPlaying = true;
}


void Gravity::gravity()
{	
		GetOwner()->SetPosition((GetOwner()->GetPosition() + Maths::Vector2f::Up));

}