//
// Created by conor on 23/04/2026.
//

#ifndef A_BUGS_LIFE_BOARD_H
#define A_BUGS_LIFE_BOARD_H


class Board {
private:
    int width;
    int height;
public:
    Board(int width, int height);
    ~Board();

    void displayAllBugs();
    void GetBugByID(int id);
    void displayHistoryOfAllBugs();
};


#endif //A_BUGS_LIFE_BOARD_H