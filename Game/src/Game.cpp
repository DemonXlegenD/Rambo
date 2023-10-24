#include "Game.h"


void Game::run() {
    Scene scene;

    sf::Texture ImageBongo;

    ImageBongo.loadFromFile("Sprite/enemy/grunt_run.png");
    

    GameObject* player = scene.CreateCharacterGameObject("Player", 200.f, ImageBongo, 2.5f, 2.5f);

    auto window = new sf::RenderWindow(sf::VideoMode(600, 600), "SFML PROJECTTTTTTTTTTTTTTTTTT", sf::Style::Fullscreen);

    while (window->isOpen())
    {




        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
            if (event.type == sf::Event::KeyPressed)
                if (event.key.code == sf::Keyboard::D)
                    player->SetPosition(player->GetPosition() + Maths::Vector2f::Right);
                if (event.key.code == sf::Keyboard::Q)
                    player->SetPosition(player->GetPosition() + Maths::Vector2f::Left);
                if (event.key.code == sf::Keyboard::Z)
                    player->SetPosition(player->GetPosition() + Maths::Vector2f::Down);
                if (event.key.code == sf::Keyboard::S)
                    player->SetPosition(player->GetPosition() + Maths::Vector2f::Up);
        }

        scene.Update();
        window->clear(sf::Color::Black);
        scene.Render(window);
        window->display();
    }
}