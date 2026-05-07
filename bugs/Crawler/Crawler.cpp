//
// Created by conor on 23/04/2026.
//

#include "Crawler.h"

#include <iostream>

using namespace std;

Crawler::Crawler(int id, pair<int, int> position, int direction, int health) : Bug(id,position,direction,health) {
    path.push_back(position);
}

string Crawler::getType() const {
    return "Crawler";
}

void Crawler::move() {
    while (isWayBlocked()) {
        direction++;
        if (direction > 4) {
            direction = 1;
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