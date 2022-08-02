#ifndef MINESWEEPER_GAME_H
#define MINESWEEPER_GAME_H

#include "Board.h"
#include "MenuWindow.h"
#include <iostream>
#include <SFML/Graphics.hpp>


class Game {
private:
    MenuWindow menu;
public:
    explicit Game();

    void Run();
};

#endif //MINESWEEPER_GAME_H
