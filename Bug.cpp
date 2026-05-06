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

//Getters
int Bug::getId() const {
    return id;
}

pair<int,int> Bug::getPosition() const {
    return position;
}

int Bug::getDirection() const {
    return direction;
}

int Bug::getHealth() const {
    return health;
}
//Setters
void Bug::setHealth(int health) {
    this->health = health;
}
void Bug::setAlive(bool alive)
{
    this -> alive = alive;
}

void Bug::setPosition(pair<int,int> position) {
    this->position = position;
}

void Bug::setDirection(int direction) {
    this->direction = direction;
}

void Bug::setId(int id) {
    this->id = id;
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