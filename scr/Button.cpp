#include "../headers/Button.h"

Button::Button(float sizeX, float sizeY, float positionX, float positionY)  : sf::RectangleShape(sf::Vector2f(sizeX, sizeY))
{
    setPosition(positionX,positionY);
}

bool Button::click(const sf::Vector2i& mouse_pos) const {
    return getGlobalBounds().contains(mouse_pos.x, mouse_pos.y);
}


