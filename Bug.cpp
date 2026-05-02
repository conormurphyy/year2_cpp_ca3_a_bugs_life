//
// Created by conor on 23/04/2026.
//

#include "Bug.h"

Bug::Bug(int id, pair<int,int> position, int direction, int health) {
    this->id = id;
    this->position = position;
    this->direction = direction;
    this->health = health;
    alive = true;
}

bool Bug::isWayBlocked() {
    if (direction == 1 && position.second == 0) {
        return true;
    }
    if (direction == 2 && position.first == 9) {
        return true;
    }
    if (direction == 3 && position.second == 9) {
        return true;
    }
    if (direction == 4 && position.first == 0) {
        return true;
    }
    return false;
}