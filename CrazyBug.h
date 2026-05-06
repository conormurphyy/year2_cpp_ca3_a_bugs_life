//
// Created by conor on 5/6/26.
//

#ifndef A_BUGS_LIFE_CRAZYBUG_H
#define A_BUGS_LIFE_CRAZYBUG_H
#include "Bug.h"


class CrazyBug: public Bug{
public:
    CrazyBug(int id, pair<int,int> position, int direction, int health);
    void move()override;
    string getType() const override;
};



#endif //A_BUGS_LIFE_CRAZYBUG_H
