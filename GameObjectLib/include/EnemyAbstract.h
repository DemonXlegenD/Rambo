#pragma once
#include "../../Game/include/Game.h"
#include "../GameObjectLib/include/Scene.h"

class EnemyAbstract {
protected: 
	int vie; 
	int degat; 
	int speed;
	Scene scene;
	sf::Texture enemy;

	GameObject* enemy = scene.CreateCharacterGameObject("Enemy", 200.f, enemy, 2.5f, 2.5f);

	int pvEnemy(int degat);
};
