#include "Button.h"
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>

#ifndef MINESWEEPER_MENUWINDOW_H
#define MINESWEEPER_MENUWINDOW_H

enum Difficulty{
    NOTCHOSEN , EASY, NORMAL, HARD
};

class MenuWindow : public sf::RenderWindow{
private:
    Difficulty difficulty = Difficulty::NOTCHOSEN;
    std::vector<Button> DifficultyButtons;
    Button PlayButton = Button(100,50,206,400);
public:
    explicit MenuWindow();

    const Difficulty getDifficulty() ;

    void setDifficulty(Difficulty dif);

    bool PlayButClick(const Window& relativeTo) const;

    void DifficultySelect(const Window& relativeTo);

    void DrawMenu();
};


#endif //MINESWEEPER_MENUWINDOW_H
