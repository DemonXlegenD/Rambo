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


<<<<<<< HEAD

	GameObject* player = config->getActualScene()->CreateCharacterGameObject("Player", 200.f, 400.f, ImageBongo, 2.5f, 2.5f);
=======
	//GameObject* player = config->getActualScene()->CreateCharacterGameObject("Player", 200.f, 400.f, ImageBongo, 2.5f, 2.5f);
>>>>>>> 7c37013a955fb2f6a86dae3c048b930826348ecc
	sf::RenderWindow* window = config->getWindow();

	while (window->isOpen())
	{


		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
<<<<<<< HEAD
			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::D) {
					std::cout << "pressD" << std::endl;
					player->SetPosition(player->GetPosition() + Maths::Vector2f::Right);
				}

				if (event.key.code == sf::Keyboard::Q)
					player->SetPosition(player->GetPosition() + Maths::Vector2f::Left);
				if (event.key.code == sf::Keyboard::Z)
					player->SetPosition(player->GetPosition() + Maths::Vector2f::Down);
				if (event.key.code == sf::Keyboard::S)
					player->SetPosition(player->GetPosition() + Maths::Vector2f::Up);
			}

=======
			//if (event.type == sf::Event::KeyPressed)
			//	if (event.key.code == sf::Keyboard::D)
			//		player.SetPosition(player.GetPosition() + Maths::Vector2f::Right);
			//if (event.key.code == sf::Keyboard::Q)
			//	player.SetPosition(player.GetPosition() + Maths::Vector2f::Left);
			//if (event.key.code == sf::Keyboard::Z)
			//	player.SetPosition(player.GetPosition() + Maths::Vector2f::Down);
			//if (event.key.code == sf::Keyboard::S)
			//	player.SetPosition(player.GetPosition() + Maths::Vector2f::Up);
>>>>>>> 7c37013a955fb2f6a86dae3c048b930826348ecc
		}
		// TODO: Ceci est un exemple de TODO
		config->Update();

	}
}