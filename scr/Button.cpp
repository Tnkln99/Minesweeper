#include "../headers/Button.h"

Button::Button(float sizeX, float sizeY, float positionX, float positionY,sf::Color color, std::string text = "")  : sf::RectangleShape(sf::Vector2f(sizeX, sizeY))
{
    setFillColor(color);
    loadText(text);
    Text.setPosition(positionX + 10,positionY + 10);
    setPosition(positionX,positionY);
}

bool Button::click(const sf::Vector2i& mouse_pos) const {
    return getGlobalBounds().contains(mouse_pos.x, mouse_pos.y);
}

void Button::setText(const std::string& text) {
    std::string fontFile = "../resources/Vanosky.otf";
    if (!Font.loadFromFile(fontFile))
    {
        std:: cout << "cant load the font" << std::endl;
        exit(1);
    }
    Text.setFont(Font);
    Text.setString(text);
    Text.setFillColor(sf::Color::Blue);
    Text.setCharacterSize(10);
}

sf::Text &Button::getText() {
    return Text;
}

void Button::loadText(const std::string& text) {
    std::string fontFile = "../resources/Vanosky.otf";
    if (!Font.loadFromFile(fontFile))
    {
        std:: cout << "cant load the font" << std::endl;
        exit(1);
    }
    Text.setFont(Font);
    Text.setString(text);
    Text.setFillColor(sf::Color::Blue);
    Text.setCharacterSize(16);
}






