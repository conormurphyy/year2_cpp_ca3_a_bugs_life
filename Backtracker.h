//
// Created by conor on 05/05/2026.
//

#ifndef A_BUGS_LIFE_BACKTRACKER_H
#define A_BUGS_LIFE_BACKTRACKER_H
#include "Bug.h"

//Moves 1 step but when it is blocked it goes in the opposite direction. For example north to south, instead of being random.
class Backtracker : public Bug {
    public:
    Backtracker(int id, pair<int,int> position, int direction, int health);
    void move() override;
    string getType() const override;
};


#endif //A_BUGS_LIFE_BACKTRACKER_H