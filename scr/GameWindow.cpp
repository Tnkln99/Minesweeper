#include "../headers/GameWindow.h"

GameWindow::GameWindow() : sf::RenderWindow() {

}

bool GameWindow::BackButtonControl(const Window& relativeTo){
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && ExitButton.click(sf::Mouse::getPosition(relativeTo))){
        Board.getField().clear();
        return true;
    }
    return false;
}

class Board &GameWindow::getBoard() {
    return Board;
}

void GameWindow::nextTurn(const Window& relativeTo) {
    for(int i = 0 ; i < Board.getField().size(); i ++){
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && Board.getField()[i].click(sf::Mouse::getPosition(relativeTo)))
        {
            if(Board.getField()[i].doesHaveMine()){
                Board.getField().clear();
            }
            else{
                Board.openSpace(i);
                for (auto & button : Board.getField()){
                    button.setMarked(false);
                }
            }
        }
    }
}

void GameWindow::DrawGame() {
    draw(ExitButton);
    draw(ExitButton.getText());
    for (auto & button : Board.getField()){
        draw(button);
        if(button.getText().getString() != "" && button.getText().getString() != "0")
            draw(button.getText());
    }
}
