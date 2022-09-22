#include "../headers/MenuWindow.h"

MenuWindow::MenuWindow() : sf::RenderWindow(sf::VideoMode(500, 500, 32), "Menu", sf::Style::Titlebar | sf::Style::Close) {
    std::string fontFile = "../resources/Vanosky.otf";
    if (!MenuFont.loadFromFile(fontFile))
    {
        std:: cout << "cant load the font" << std::endl;
        exit(1);
    }
    titleText.setFont(MenuFont);
    titleText.setString("MINESWEEPER");
    titleText.setCharacterSize(25);
    titleText.setStyle(sf::Text::Bold);
    titleText.setPosition(150,25);
    titleText.setFillColor(sf::Color::Red);

    highScoreText.setFont(MenuFont);
    highScoreText.setString("HIGHEST SCORE :");
    highScoreText.setCharacterSize(25);
    //highScoreText.setStyle(sf::Text::Bold);
    highScoreText.setPosition(150,225);
    highScoreText.setFillColor(sf::Color::Red);

    highestScore.setFont(MenuFont);
    highestScore.setString("0");
    highestScore.setCharacterSize(25);
    //highestScore.setStyle(sf::Text::Bold);
    highestScore.setPosition(250,275);
    highestScore.setFillColor(sf::Color::Red);

    DifficultyButtons.push_back(std::make_unique<Button>(100,50,56,100,sf::Color::Cyan, "Easy"));
    DifficultyButtons.push_back(std::make_unique<Button>(100,50,206,100,sf::Color::Cyan, "Normal"));
    DifficultyButtons.push_back(std::make_unique<Button>(100,50,356,100,sf::Color::Cyan, "Hard"));
}

bool MenuWindow::PlayButClick(const Window& relativeTo) const {
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && PlayButton.click(sf::Mouse::getPosition(relativeTo)))
        return true;
    return false;
}

Difficulty MenuWindow::getDifficulty() {
    return difficulty;
}


void MenuWindow::setDifficulty(Difficulty dif) {
    difficulty = dif;
}


void MenuWindow::DifficultySelect(const Window& relativeTo) {
    for(int i = 0; i < DifficultyButtons.size(); i ++ ){
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && DifficultyButtons[i]->click(sf::Mouse::getPosition(relativeTo))){
            DifficultyButtons[i]->setFillColor(sf::Color(0,51,51));
            int savedIndex = i;
            for(int j = 0; j < 3; j++){
                if (j != savedIndex)
                    DifficultyButtons[j]->setFillColor(sf::Color::Cyan);
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
        draw(*button);
        draw(button->getText());
    }

    draw(titleText);
    draw(highScoreText);
    draw(highestScore);

    draw(PlayButton);
    draw(PlayButton.getText());
}

