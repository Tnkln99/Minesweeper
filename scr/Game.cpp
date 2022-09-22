#include "../headers/Game.h"

Game::Game() = default;

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
            res.first = 900;
            res.second = 900;
            break;
        default:
            break;
    }
    return res;
}

void Game::Run() //main function
{
    while(gameRunning){
        while (menu.isOpen())
        {
            sf::Event event{};
            while (menu.pollEvent(event))
            {
                if (event.type == sf::Event::Closed){
                    menu.close();
                    game.close();
                    gameRunning = false;
                }
            }

            if(menu.PlayButClick(menu))
            {
                menu.close();
                std::pair<int,int> difficultySetting = DifficultyToSize(menu.getDifficulty());
                game.create(sf::VideoMode(difficultySetting.first, difficultySetting.second, 32), "MinesSweeper", sf::Style::Titlebar | sf::Style::Close);
                game.getBoard().loadBoard(difficultySetting.first/50);
            }
            menu.DifficultySelect(menu);

            menu.clear();
            menu.DrawMenu();
            menu.display();
        }

        /*----------------------------------------------------------------------------------------------------------*/

        while(game.isOpen()){
            sf::Event event{};
            while (game.pollEvent(event))
            {
                if (event.type == sf::Event::Closed){
                    game.close();
                    gameRunning = false;
                }
            }
            if(game.BackButtonControl(game)){
                game.close();
                menu.create(sf::VideoMode(500, 500, 32), "Menu", sf::Style::Titlebar | sf::Style::Close);
            }

            game.nextTurn(game);


            game.clear();
            game.DrawGame();
            game.display();
        }
    }

}