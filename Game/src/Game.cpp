#include "Game.h"

Game::Game() {
	this->config = new GameConfig();
	this->state = new GameState();
	this->stats = new GameStats();
	this->log = new GameLog();
}

void Game::run() {

	sf::Texture ImageBongo;
	config->Preload();
	ImageBongo.loadFromFile("assets/Sprite/player/john_static.png");



	//GameObject* player = config->getActualScene()->CreateCharacterGameObject("Player", 200.f, 400.f, ImageBongo, 2.5f, 2.5f);
	sf::RenderWindow* window = config->getWindow();

	while (window->isOpen())
	{


		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
			//if (event.type == sf::Event::KeyPressed)
			//	if (event.key.code == sf::Keyboard::D)
			//		player->SetPosition(player->GetPosition() + Maths::Vector2f::Right);
			//if (event.key.code == sf::Keyboard::Q)
			//	player->SetPosition(player->GetPosition() + Maths::Vector2f::Left);
			//if (event.key.code == sf::Keyboard::Z)
			//	player->SetPosition(player->GetPosition() + Maths::Vector2f::Down);
			//if (event.key.code == sf::Keyboard::S)
			//	player->SetPosition(player->GetPosition() + Maths::Vector2f::Up);
		}
		// TODO: Ceci est un exemple de TODO
		config->Update();

	}
}