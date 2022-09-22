#include "FieldButton.h"
#include "Board.h"
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>

#ifndef MINESWEEPER_GAMEWINDOW_H
#define MINESWEEPER_GAMEWINDOW_H

class GameWindow : public sf::RenderWindow{
private:
    Button ExitButton = Button(100, 50, 50, 50, sf::Color(51, 0, 102), "EXIT");
    Board Board;
public:
    explicit GameWindow();

    bool BackButtonControl(const Window& relativeTo);
    class Board & getBoard();

    void nextTurn(const Window& relativeTo);
    void DrawGame();
};

#endif //MINESWEEPER_GAMEWINDOW_H
