#include "../headers/MenuWindow.h"

MenuWindow::MenuWindow() : sf::RenderWindow(sf::VideoMode(500, 500, 32), "Menu") {
    DifficultyButtons.emplace_back(100,50,56,100);
    DifficultyButtons.emplace_back(100,50,206,100);
    DifficultyButtons.emplace_back(100,50,356,100);
}

bool MenuWindow::PlayButClick(const Window& relativeTo) const {
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && PlayButton.click(sf::Mouse::getPosition(relativeTo)))
        return true;
    return false;
}

const Difficulty MenuWindow::getDifficulty() {
    return difficulty;
}


void MenuWindow::setDifficulty(Difficulty dif) {
    difficulty = dif;
}


void MenuWindow::DifficultySelect(const Window& relativeTo) {
    for(int i = 0; i < DifficultyButtons.size(); i ++ ){
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && DifficultyButtons[i].click(sf::Mouse::getPosition(relativeTo))){
            DifficultyButtons[i].setFillColor(sf::Color::Green);
            int savedIndex = i;
            for(int j = 0; j < 3; j++){
                if (j != savedIndex)
                    DifficultyButtons[j].setFillColor(sf::Color::White);
            }
            switch (savedIndex) {
                case 0:
                    setDifficulty(Difficulty::EASY);
                    break;
                case 1:
                    setDifficulty(Difficulty::NORMAL);
                    break;
                case 2:
                    setDifficulty(Difficulty::HARD);
                    break;
                default:
                    break;
            }
        }
    }
}

void MenuWindow::DrawMenu() {
    for (auto & button : DifficultyButtons){
        draw(button);
    }
    draw(PlayButton);
}

