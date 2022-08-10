#include "../headers/GameWindow.h"

GameWindow::GameWindow() : sf::RenderWindow() {

}

bool GameWindow::BackButtonControl(const Window& relativeTo) const {
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && ExitButton.click(sf::Mouse::getPosition(relativeTo)))
        return true;
    return false;
}

void GameWindow::DrawGame() {
    draw(ExitButton);
    draw(ExitButton.getText());
}
