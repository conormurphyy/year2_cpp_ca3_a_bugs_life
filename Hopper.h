//
// Created by conor on 23/04/2026.
//

#ifndef A_BUGS_LIFE_HOPPER_H
#define A_BUGS_LIFE_HOPPER_H

#include "Bug.h"

class Hopper : public Bug {
protected:
    int hopLength;
public:
    Hopper(int id, pair<int,int> position, int direction, int health, int hopLength);

    void move() override;

    string getType() const override;


};


#endif //A_BUGS_LIFE_HOPPER_H