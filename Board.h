//
// Created by conor on 23/04/2026.
//

#ifndef A_BUGS_LIFE_BOARD_H
#define A_BUGS_LIFE_BOARD_H
#include <vector>

#include "Bug.h"

class Board {
private:
    int width;
    int height;
    std::vector<Bug*> bugs;
public:
    Board(int width, int height);
    ~Board();

    void loadBugs();
    void displayAllBugs();
    void GetBugByID(int id);

    void displayAllCells();

    void displayALlCells();

    void tap();

    void displayHistoryOfAllBugs();
};


#endif //A_BUGS_LIFE_BOARD_H