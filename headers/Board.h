#include <ctime>
#include <cstdlib>

#ifndef MINESWEEPER_BOARD_H
#define MINESWEEPER_BOARD_H

class Board {
private:
    int size{};
    bool* field{}; //false if no mine true there is mine on that index
    int numberOfMine{};
public:
    explicit Board();

    void SetParameters(int);

    void DrawBoard() const;
    void loadBoard();
};


#endif //MINESWEEPER_BOARD_H
