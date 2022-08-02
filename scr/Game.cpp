#include "../headers/Game.h"

Game::Game() = default;

void Game::Run() //main function
{
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (menu.isOpen())
    {
        sf::Event event{};
        while (menu.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                menu.close();
        }

        if(/*sf::Mouse::isButtonPressed(sf::Mouse::Left) &&*/ menu.PlayButClick())
            std::cout<<"clicked"<<std::endl;

        menu.clear();
        menu.DrawMenu();
        menu.display();
    }
}


