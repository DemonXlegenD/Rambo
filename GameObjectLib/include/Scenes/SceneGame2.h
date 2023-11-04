#pragma once
#include <SFML/Graphics.hpp>

#include "SceneGameAbstract.h"
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h> 

class SceneGame2 : public SceneGameAbstract
{
public:
	SceneGame2(sf::RenderWindow* window);

	void Awake() override;


	void CreateTurret(sf::Texture texture);



	bool PauseMenu(bool gamePause);



	//TODO: ajouter la texture
	void CreatePlatform(sf::Texture texture);
	
	void Create() override;
	void Update(sf::Time _delta) override;
	void Render(sf::RenderWindow* _window) override;

private:
	GameObject* turret1 = nullptr;
	GameObject* turret2 = nullptr;
	GameObject* player = nullptr;
	sf::Texture* texture;
	bool gamePause = false;
	bool escapeIsPress = true;
};


