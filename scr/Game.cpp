#include "../headers/Game.h"

Game::Game() = default;

void Game::Run() //main function
{

    while (menu.isOpen())
    {
        sf::Event event{};
        while (menu.pollEvent(event))
        {
            if (event.type == sf::Event::Closed){
                menu.close();
                game.close();
            }
        }

        if(menu.PlayButClick(menu))
        {
            menu.close();
            std::pair<int,int> difficultySetting = DifficultyToSize(menu.getDifficulty());
            game.create(sf::VideoMode(difficultySetting.first, difficultySetting.second, 32), "MinesSweeper");
        }
        menu.DifficultySelect(menu);

        menu.clear();
        menu.DrawMenu();
        menu.display();
    }

    while(game.isOpen()){
        sf::Event event{};
        while (game.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                game.close();
        }

        game.clear();
        game.display();
    }
}

std::pair<int, int> Game::DifficultyToSize(Difficulty dif) {
    std::pair<int,int> res;
    switch (dif) {
        case Difficulty::EASY:
            res.first = 500;
            res.second = 500;
            break;
        case Difficulty::NORMAL:
            res.first = 750;
            res.second = 750;
            break;
        case Difficulty::HARD:
            res.first = 1000;
            res.second = 1000;
            break;
        default:
            break;
    }
    return res;
}


