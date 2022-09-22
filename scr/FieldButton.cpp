#include "../headers/FieldButton.h"

FieldButton::FieldButton(int posX, int posY) : Button(25,25,posX,posY,sf::Color(64,64,64),""){
    setOutlineThickness(1);
    setOutlineColor(sf::Color(128,128,128));
}

void FieldButton::setHaveMine(bool haveMine) {
    this->haveMine = haveMine;
}

void FieldButton::setNeighborCount(int count) {
    neighborCount = count;
}

bool FieldButton::doesHaveMine() const {
    return haveMine;
}

int FieldButton::getNeighborCount() const {
    return neighborCount;
}

void FieldButton::setMarked(bool M) {
    this->isMarked = M;
}

bool FieldButton::getIsMarked() const {
    return isMarked;
}


