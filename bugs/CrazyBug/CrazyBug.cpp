//
// Created by conor on 5/6/26.
//

#include "CrazyBug.h"

#include "../Bug.h"
#include <cstdlib>

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

    while (isWayBlocked())
    {
        direction++;
        if (direction>4)
        {
            direction =1;
        }
    }


    if (direction == 1) {
        position.second = position.second + rand() % 5;
    }
    else if (direction == 2) {
        position.first = position.first + rand() % 5;
    }
    else if (direction == 3) {
        position.second = position.second + rand() % 5;
    }
    else if (direction == 4) {
        position.first = position.first + rand() % 5;
    }
    else {
        cout << "Error" << endl;
    }
    if (position.first < 0)
    {
        position.first = 0;
        direction=2;
    }
    if (position.first >9)
    {
        position.first = 9;
        direction=4;
    }
    if (position.second < 0)
    {
        position.second = 0;
        direction=3;
    }
    if (position.second >9)
    {
        position.second = 9;
        direction=1;
    }
    path.push_back(position);
}