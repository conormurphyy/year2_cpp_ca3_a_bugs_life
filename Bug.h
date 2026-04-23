//
// Created by conor on 23/04/2026.
//

#ifndef A_BUGS_LIFE_BUG_H
#define A_BUGS_LIFE_BUG_H
#include <iostream>
#include <list>

using namespace std;

class Bug {
protected:
    //Protected Fields
    int id;
    pair<int,int> position;
    int direction;
    int health;
    bool alive;
    list<pair<int, int>> path;

public:
    Bug(int id, pair<int, int> position, int direction, int health) {
        this->id = id;
        this->position = position;
        this->direction = direction;
        this->health = health;
    }

};


#endif //A_BUGS_LIFE_BUG_H