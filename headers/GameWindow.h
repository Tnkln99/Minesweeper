#include "Button.h"
#include "Board.h"
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>

#ifndef MINESWEEPER_GAMEWINDOW_H
#define MINESWEEPER_GAMEWINDOW_H

class GameWindow : public sf::RenderWindow{
private:
    Button ExitButton = Button(100, 50, 50, 50, sf::Color(51, 0, 102), "EXIT");
    std::vector<Button> Buttons;
public:
    explicit GameWindow();

    bool BackButtonControl(const Window& relativeTo) const;

    void DrawGame();
};

#endif //MINESWEEPER_GAMEWINDOW_H
