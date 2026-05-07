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
    Bug(int id, pair<int, int> position, int direction, int health);

    virtual void move() = 0;
    bool isWayBlocked();


    //Getters
    virtual string getType() const = 0;
    virtual int getHopLength() const {
        return -1;
    };

    const list<pair<int, int>>& getPath() const { return path; }

    int getId() const;
    pair<int, int> getPosition() const;
    int getDirection() const;
    int getHealth() const;

    //Setters
    void setId(int id);
    void setPosition(pair<int, int> position);
    void setDirection(int direction);
    void setHealth(int health);
    void setAlive(bool alive);

    bool isAlive(){return alive;}


};


#endif //A_BUGS_LIFE_BUG_H