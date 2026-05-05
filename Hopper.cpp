//
// Created by conor on 23/04/2026.
//

#include "Hopper.h"

Hopper::Hopper(int id, pair<int,int> position, int direction, int health, int hopLength) : Bug(id,position,direction,health) {
    this->hopLength = hopLength;
}



string Hopper::getType() const {
    return "Hopper";
}



void Hopper::move() {
    while (isWayBlocked()) {
        direction++;
        if (direction > 4) {
            direction = 1;
        }
    }

    for (int i = 0; i < hopLength; i++) {
        if (isWayBlocked()) {
            break;
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




}
