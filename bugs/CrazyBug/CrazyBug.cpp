//
// Created by conor on 5/6/26.
//

#include "CrazyBug.h"

#include "../Bug.h"

CrazyBug::CrazyBug(int id, pair<int,int> position, int direction,int health): Bug(id,position,direction,health)
{
    path.push_back(position);
}

string CrazyBug::getType() const
{
    return "CrazyBug";
}
void CrazyBug:: move()
{
    if (isWayBlocked()) {
        if (direction == 1) {
            direction = 2;
        }
        else if (direction == 2) {
            direction = 1;
        }
        else if (direction == 3) {
            direction = 4;
        }
        else if (direction == 4) {
            direction = 3;
        }
    }

    if (direction == 1) {
        position.second = position.second + 2;
    }
    else if (direction == 2) {
        position.first = position.first + 2;
    }
    else if (direction == 3) {
        position.second = position.second - 4;
    }
    else if (direction == 4) {
        position.first = position.first + 2;
    }
    else {
        cout << "Error" << endl;
    }
    path.push_back(position);
}