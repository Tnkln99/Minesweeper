#include "../headers/MenuWindow.h"

MenuWindow::MenuWindow() : sf::RenderWindow(sf::VideoMode(500, 500, 32), "Menu") {
    Buttons.emplace_back(100,100,200,200);
}

bool MenuWindow::PlayButClick() const {
    if(Buttons[0].click(sf::Mouse::getPosition())) // relative to windows yapmak gerek
        return true;
    else
        return false;
}

void MenuWindow::DrawMenu() {
    for (auto & button : Buttons){
        draw(button);
    }
}


