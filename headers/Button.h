#include <iostream>
#include <SFML/Graphics.hpp>

#ifndef MINESWEEPER_BUTTON_H
#define MINESWEEPER_BUTTON_H

class Button : public sf::RectangleShape {
private:
    sf::Text Text;
public:
    Button(float,float,float,float);

    bool click(const sf::Vector2i& mouse_pos) const;
};
#endif //MINESWEEPER_BUTTON_H
