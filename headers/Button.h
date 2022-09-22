#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

#ifndef MINESWEEPER_BUTTON_H
#define MINESWEEPER_BUTTON_H

class Button : public sf::RectangleShape {
private:
    sf::Text Text;
    sf::Font Font;
public:
    Button(float,float,float,float,sf::Color,const std::string);

    void setText(const std::string&);

    sf::Text & getText();

    void loadText(const std::string& text);
    bool click(const sf::Vector2i& mouse_pos) const;
};
#endif //MINESWEEPER_BUTTON_H
