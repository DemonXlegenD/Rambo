#pragma once

#include <SFML/Graphics.hpp>

#include "GameObject.h"
#include "Scene.h"

#include "Game/GameConfig.h"
#include "Game/GameStats.h"
#include "Game/GameState.h"
#include "Game/GameLog.h"


class Game
{
public:
	void run();
	GameConfig* getConfig() const { return config; }
	GameLog* getLog() const { return log; }
	GameState* getState() const { return state; }
	GameStats* getStats() const { return stats; }

private:
	GameConfig* config;
	GameLog* log;
	GameState* state;
	GameStats* stats;
};

