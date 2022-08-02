#include "../headers/Board.h"

Board::Board()= default;

void Board::SetParameters(int size){
    this->size = size * size;
    numberOfMine = size * 3;

    loadBoard();
}

void Board::DrawBoard() const {
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){

        }
    }
}

void Board::loadBoard() {
    field = new bool[size];
    for(int i = 0; i < numberOfMine; i ++){
        srand(time(nullptr));
        int r = rand() % (size * size);

        while(!field[r])
            r = rand() % (size * size);

        field[r] = true;
    }
}


