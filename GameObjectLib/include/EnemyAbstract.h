#pragma once
#include "../../Game/include/Game.h"
#include "../GameObjectLib/include/Scene.h"

class EnemyAbstract {
private: 
	int vie; 
	int degat; 
	Scene scene;
	sf::Texture ImageBongo;

	//GameObject* enemy = scene.CreateCharacterGameObject("Player", 200.f, ImageBongo, 2.5f, 2.5f);
};
