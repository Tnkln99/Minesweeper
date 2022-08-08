#ifndef MINESWEEPER_GAME_H
#define MINESWEEPER_GAME_H

#include "Board.h"
#include "MenuWindow.h"
#include "GameWindow.h"
#include <iostream>
#include <SFML/Graphics.hpp>


class Game {
private:
    MenuWindow menu;
    GameWindow game;
public:
    explicit Game();

    std::pair<int, int> DifficultyToSize(Difficulty dif);

    void Run();
};

#endif //MINESWEEPER_GAME_H
