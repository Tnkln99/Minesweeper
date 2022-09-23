#include "../headers/Board.h"

Board::Board() = default;

void Board::loadBoard(int sizeOfBoard) {
    this->SizeOfBoard = sizeOfBoard;
    int marginX;
    int marginY;
    if(sizeOfBoard == 10){
        marginX = 130;
        marginY = 150;
        MineNumber = 20;
    }
    else if (sizeOfBoard == 15){
        marginX = 170;
        marginY = 195;
        MineNumber = 45;
    }
    else{
        marginX = 200;
        marginY = 215;
        MineNumber = 60;
    }
    for(int i = 0; i < sizeOfBoard; i ++){
        for(int j = 0; j < sizeOfBoard; j ++){
            Field.push_back(FieldButton(i * 30 + marginX, j * 30 + marginY));
        }
    }
    srand(time(0));
    int totalSizeOfBoard = sizeOfBoard * sizeOfBoard;
    for (int i = 0; i < MineNumber; i ++){
        int r = rand() % totalSizeOfBoard;
        //std::cout<<r<<std::endl;
        while(Field[r].doesHaveMine()){
            r = rand() % totalSizeOfBoard;
        }
        Field[r].setHaveMine(true);
    }

    //debugger();

    for (int i = 0; i < Field.size(); i++){
        Field[i].setNeighborCount(findNeighbourMineCount(i));
    }
}

void Board::openSpace(int index) {
    int i = index / SizeOfBoard;
    int j = index % SizeOfBoard;
    Field[index].setMarked(true);
    Field[index].setFillColor(sf::Color::White);
    if(Field[index].getNeighborCount() == 0 && index < Field.size())
    {
        if(i * SizeOfBoard + j + 1 <= Field.size() && j != SizeOfBoard-1 && !Field[i * SizeOfBoard + j + 1].getIsMarked()){
            openSpace(i * SizeOfBoard + j + 1);
        }
        if(i * SizeOfBoard + j - 1 >= 0 && j != 0 && !Field[i * SizeOfBoard + j - 1].getIsMarked()){
            openSpace(i * SizeOfBoard + j - 1);
        }
        if((i+1) * SizeOfBoard + j <= Field.size() && !Field[(i+1) * SizeOfBoard + j].getIsMarked()){
            openSpace((i+1) * SizeOfBoard + j);
        }
        if((i-1) * SizeOfBoard + j >= 0 && !Field[(i-1) * SizeOfBoard + j].getIsMarked()){
            openSpace((i-1) * SizeOfBoard + j);
        }
        if((i+1) * SizeOfBoard + j + 1 <= Field.size() && j != SizeOfBoard-1 && !Field[(i+1) * SizeOfBoard + j + 1].getIsMarked()){
            openSpace((i+1) * SizeOfBoard + j + 1);
        }
        if((i+1) * SizeOfBoard + j - 1 >= 0 && j != 0 && !Field[(i+1) * SizeOfBoard + j - 1].getIsMarked()){
            openSpace((i+1) * SizeOfBoard + j - 1);
        }
        if((i-1) * SizeOfBoard + j-1 <= Field.size() && j != 0 && !Field[(i-1) * SizeOfBoard + j - 1].getIsMarked()){
            openSpace((i-1) * SizeOfBoard + j-1);
        }
        if((i-1) * SizeOfBoard + j+1 >= 0 && j != SizeOfBoard-1 && !Field[(i-1) * SizeOfBoard + j+1].getIsMarked()){
            openSpace((i-1) * SizeOfBoard + j+1);
        }
    }
    else if(Field[index].getNeighborCount()>0){
        std::string neighborStr = std::to_string(findNeighbourMineCount(index));
        Field[index].setText(neighborStr);
        return;
    }
    else
        return;
}

const int Board::findNeighbourMineCount(int index) {
    int i = index / SizeOfBoard;
    int j = index % SizeOfBoard;

    int Vkinit, Vkfin, Vpinit,Vpfin;

    if (i == 0) {Vkinit = i; Vkfin = i + 1;}
    else if (i == SizeOfBoard - 1) { Vkfin = i; Vkinit = i - 1; }
    else { Vkinit = i - 1; Vkfin = i + 1; }

    if (j == 0) { Vpinit = j; Vpfin = j + 1; }
    else if (j == SizeOfBoard - 1) { Vpfin = j; Vpinit = j - 1; }
    else { Vpinit = j - 1; Vpfin = j + 1; }

    int res = 0;

    for (int k = Vkinit; k <= Vkfin; k++) {
        for (int p = Vpinit; p <= Vpfin; p++) {
            if(Field[k * SizeOfBoard + p].doesHaveMine())
                res++;
        }
    }
    return res;
}

std::vector<FieldButton> &Board::getField() {
    return Field;
}

void Board::debugger() {
    for (auto & button : Field){
        if(button.doesHaveMine())
            button.setFillColor(sf::Color::Red);
    }
}


