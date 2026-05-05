//
// Created by conor on 23/04/2026.
//

#ifndef A_BUGS_LIFE_CRAWLER_H
#define A_BUGS_LIFE_CRAWLER_H

#include "Bug.h"

class Crawler : public Bug {
public:
    Crawler(int id, pair<int, int> position, int direction, int health);
    void move() override;

    string getType() const override;
};


#endif //A_BUGS_LIFE_CRAWLER_H