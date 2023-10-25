#pragma once
#include "../../Game/include/Game.h"
#include "../GameObjectLib/include/Scene.h"

class EnemyAbstract {
public:
	EnemyAbstract();
	EnemyAbstract(int _hp, int _damage, int _speed);
protected: 
	int hp;
	int damage;
	int speed;
	Scene scene;
	sf::Texture enemy;


	int pvEnemy(int degat);
};
