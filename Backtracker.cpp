//
// Created by conor on 05/05/2026.
//

#include "Backtracker.h"

#include "Bug.h"

Backtracker::Backtracker(int id, pair<int, int> position, int direction, int health) :Bug(id,position,direction,health) {

}

void Backtracker::move() {
    if (isWayBlocked()) {
        if (direction == 1) {
            direction = 3;
        }
        else if (direction == 2) {
            direction = 4;
        }
        else if (direction == 3) {
            direction = 1;
        }
        else if (direction == 4) {
            direction = 2;
        }
    }

    if (direction == 1) {
        position.second = position.second - 1;
    }
    else if (direction == 2) {
        position.first = position.first + 1;
    }
    else if (direction == 3) {
        position.second = position.second + 1;
    }
    else if (direction == 4) {
        position.first = position.first - 1;
    }
    else {
        cout << "Error" << endl;
    }
    path.push_back(position);
}