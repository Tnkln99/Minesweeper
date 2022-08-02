#include "Button.h"
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>

#ifndef MINESWEEPER_MENUWINDOW_H
#define MINESWEEPER_MENUWINDOW_H

enum Difficulty{
    EASY, NORMAL, HARD
};

class MenuWindow : public sf::RenderWindow{
private:
    Difficulty difficulty;
    std::vector<Button> Buttons;


public:
    explicit MenuWindow();

    bool PlayButClick() const;

    void DrawMenu();
};


#endif //MINESWEEPER_MENUWINDOW_H
