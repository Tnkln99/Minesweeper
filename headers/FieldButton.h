#include "Button.h"

#ifndef MINESWEEPER_FIELDBUTTON_H
#define MINESWEEPER_FIELDBUTTON_H

class FieldButton : public Button {
private:
    bool haveMine = false;
    int neighborCount = 0;
    bool isMarked = false;
public:
    FieldButton(int posX, int posY);

    void setHaveMine(bool);
    void setNeighborCount(int);
    void setMarked(bool);

    bool getIsMarked() const;
    int getNeighborCount() const;
    bool doesHaveMine() const;
};

#endif //MINESWEEPER_FIELDBUTTON_H
