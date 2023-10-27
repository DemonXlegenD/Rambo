#pragma once
#include "Component.h"

class Gravity : public Component
{
public:
	Gravity();

	void Update(sf::Time _delta) override;
	void gravity();
	void stop();
	void start();
	bool isPlaying;
};

