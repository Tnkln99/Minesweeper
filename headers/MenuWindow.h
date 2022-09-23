#include "Button.h"
#include <iostream>
#include <utility>
#include <vector>
#include <SFML/Graphics.hpp>
#include <memory>

#ifndef MINESWEEPER_MENUWINDOW_H
#define MINESWEEPER_MENUWINDOW_H

enum Difficulty{
    NOTCHOSEN , EASY, NORMAL, HARD
};

class MenuWindow : public sf::RenderWindow{
private:
    Difficulty difficulty = Difficulty::NOTCHOSEN;
    std::vector<std::unique_ptr<Button>> DifficultyButtons;
    Button PlayButton = Button(100,50,206,400,sf::Color(51,0,102),"PLAY");

    sf::Text titleText;
    sf::Text highScoreTitleText;
    sf::Text highestScore;

    sf::Font MenuFont;
public:
    explicit MenuWindow();

    Difficulty getDifficulty() ;

    void setDifficulty(Difficulty dif);

    bool PlayButClick(const Window& relativeTo) const;

    void DifficultySelect(const Window& relativeTo);

    void DrawMenu();
};


#endif //MINESWEEPER_MENUWINDOW_H
