#include "Button.h"
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>

#ifndef MINESWEEPER_GAMEWINDOW_H
#define MINESWEEPER_GAMEWINDOW_H

class GameWindow : public sf::RenderWindow{
private:
    std::vector<Button> Buttons;
public:
    explicit GameWindow();
};

#endif //MINESWEEPER_GAMEWINDOW_H
