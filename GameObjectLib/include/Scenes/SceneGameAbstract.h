#pragma once

#include "Scene.h"


class SceneGameAbstract : public Scene
{
public:
	SceneGameAbstract(sf::RenderWindow* window);

	void Awake() override;

	void CreatePlayer();
	void CreateGrunt();

	void Collision(GameObject* _entity);

	bool PauseMenu() { return gamePause; }

	void ManageSceneGameButtonsPause();
	void ManageMenuPause(bool _states);
	void CreatePauseMenuButtons();

	//PLAYER 
	GameObject* CreateCharacterGameObject(const std::string& name, float positionx, float positiony, const sf::Texture texture, float scalex, float scaley);
	GameObject* CreateBulletGameObject(const std::string& name, const sf::Texture textureBullet, float scalex, float scaley, GameObject* _player);

	GameObject* CreateGruntGameObject(const std::string& name, float positionx, float positiony, float scalex, float scaley, sf::Texture _texture);

	GameObject* CreateTurretGameObject(const std::string& name, float positionx, float positiony, float scalex, float scaley, sf::Texture _texture);


	void CreatePlatform(sf::Texture texture);
	void CreateBackground();
	void Create() override;
	void Update(sf::Time _delta) override;
	void Render(sf::RenderWindow* _window) override;
	std::vector<GameObject*> GetEnemies() {return enemies;}
	GameObject* GetEnemie(int _index) {return enemies[_index];}
protected:
	//TODO : Lorsque vous retirez un ennemi du vector, il faut bien pensé à le supprimer du vector gameObjects de la Scene
	std::vector<GameObject*> platforms;
	std::vector<GameObject*> enemies;
	GameObject* player = nullptr;
	GameObject* pausePlayButton = nullptr;
	GameObject* pauseOptionsButton = nullptr;
	GameObject* pauseMenuPrincipalButton = nullptr;
	GameObject* pauseQuitButton = nullptr;
	GameObject* pauseBongoButton = nullptr;
	sf::Texture* texture;
	bool gamePause;
	bool escapeIsPress;
};

