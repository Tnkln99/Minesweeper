#include <ctime>
#include <cstdlib>
#include <vector>
#include <random>
#include <string>
#include <iostream>
#include "FieldButton.h"

#ifndef MINESWEEPER_BOARD_H
#define MINESWEEPER_BOARD_H

class Board {
private:
    std::vector<FieldButton> Field;
    int MineNumber;
    int SizeOfBoard;
public:
    explicit Board();

    void loadBoard(int);
    void openSpace(int);

    const int findNeighbourMineCount(int);

    std::vector<FieldButton> & getField();

    void debugger();
};


#endif //MINESWEEPER_BOARD_H
