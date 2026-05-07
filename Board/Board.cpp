//
// Created by conor on 23/04/2026.
//

#include "Board.h"

#include "../bugs/Bug.h"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include "../bugs/Backtracker/Backtracker.h"
#include "../bugs/Crawler/Crawler.h"
#include "../bugs/CrazyBug/CrazyBug.h"
#include "../bugs/Hopper/Hopper.h"
using namespace std;
#include <string>
#include <fstream>
Board::Board(int width, int height) {
    this->width = width;
    this->height = height;

}

void Board::loadBugs() {
    ifstream fin("bugs.txt");
    string line;
    while (getline(fin,line)) {
        std::stringstream test(line);
        std::string semicolon;
        std::vector<std::string> bugList;
        /*https://stackoverflow.com/questions/10058606/splitting-a-string-by-a-character */
        while (std::getline(test, semicolon, ';')) {
            bugList.push_back(semicolon);
        }

        /* https://www.codecademy.com/article/how-to-convert-a-string-to-an-integer-in-c */
        int id = std::stoi(bugList[1]);
        int x = std::stoi(bugList[2]);
        int y = std::stoi(bugList[3]);
        int direction = std::stoi(bugList[4]);
        int health = std::stoi(bugList[5]);

        string type = bugList[0];
        if (type == "C") {
            /* Crawler */
            pair<int, int> position = {x,y};
            char bugType = 'C';
            bugs.push_back(new Crawler(id, position, direction, health));
        }
        else if (type == "H") {
            pair<int, int> position = {x,y};
            int hopLength = std::stoi(bugList[6]);
            bugs.push_back(new Hopper(id, position, direction, health, hopLength));
        }
        else if (type == "B") {
            pair<int, int> position = {x,y};
            bugs.push_back(new Backtracker (id, position, direction, health));
        }
        else if (type == "Z")
        {
            pair<int,int> position ={x,y};
            bugs.push_back(new CrazyBug(id,position,direction,health));
        }
        else {
            cout << "Error finding bug type" << endl;
        }

    }
}

void Board::displayAllBugs() {
    cout << "ID:" << "\t\t";
    cout << "Type:" << "\t\t";
    cout << "Position:" << "\t\t\t";
    cout << "Health:" << "\t\t";
    cout << "\n" << endl;
    for (int i = 0; i < bugs.size(); i++) {
        cout << bugs[i]->getId() << "\t\t";
        cout << bugs[i]->getType() << "\t\t\\t";
        cout << "(" << bugs[i]->getPosition().first << "," << bugs[i]->getPosition().second << ")" << "\t\t\t";
        cout << bugs[i]->getHealth() << "\t\t";
        cout << "\n" << endl;
    }
}

void Board::GetBugByID(int id) {
    bool found = false;
    for (int i = 0; i < bugs.size(); i++) {
        if (bugs[i]->getId() == id) {
            cout << "Bug with ID" + id << " " << endl;
            cout << bugs[i]->getId() << " ";
            cout << bugs[i]->getType() << " ";
            cout << bugs[i]->getPosition().first << " ";
            cout << bugs[i]->getPosition().second << " ";
            cout << bugs[i]->getHealth() << " ";
            cout << endl;
            found = true;
        }
    }
    if (found == false) {
        cout << "Bug with ID" + id << " not found" << endl;
    }

}

void Board::displayAllCells() {
    for (int y = 0; y < 10; y++) {
        for (int x = 0; x < 10; x++) {
            cout << "(" << x << "," << y << ")";

            bool foundBug = false;
            for (int i = 0; i < bugs.size(); i++) {
                if (bugs[i]->getPosition().first == x && bugs[i]->getPosition().second == y) {
                    cout << bugs[i]->getId() << " ";
                    cout << bugs[i]->getType() << " ";
                    foundBug = true;
                }


            }
            if (!foundBug) {
                cout << "Empty" << " ";
            }
        }
        cout << endl;
    }
}

void Board::tap() {
    for (int i = 0; i < bugs.size(); i++) {
        if (bugs[i]-> isAlive())
        {
        bugs[i]->move();

        }
        
    }
    checkIfTwoBugsAreInSamePosition();
}

void Board::displayHistoryOfAllBugs() {
    for (int i = 0; i < bugs.size(); i++) {
        cout << bugs[i]->getId() << " ";
        cout << bugs[i]->getType() << " ";
        cout << "Path: ";
        for (auto it = bugs[i]->getPath().begin(); it != bugs[i]->getPath().end(); it++) {
            cout << "(" << it->first << ", " << it->second << ")" << " ";
        }
        cout << endl;
    }
}

void Board::writeLifeHistoryToFile()
{
    ofstream fout("lifeHistory.txt");
    string output;
    for (int i =0;i<bugs.size();i++)
    {
        string output = to_string(bugs[i]->getId()) + ";" + bugs[i]->getType() + ";" + to_string(bugs[i]->getHealth()) + "\n";
        string pathS = "";
        for (auto it = bugs[i]->getPath().begin(); it != bugs[i]->getPath().end(); it++) {
            pathS += "(" + to_string(it->first) + "," + to_string(it->second) + ")";
        }
        output += pathS;
       }
    fout << output;
    fout.close();


}
void Board::runSimulation()
{
    int tapCount=0;
    cout << "Simulation started" << endl;
    int aliveBugs=0;

    for (int i = 0; i < bugs.size(); i++)
    {
        if (bugs[i]-> isAlive())
        {
            aliveBugs++;
        }
    }

    while (aliveBugs>1)
    {
        tapCount++;
        cout << "Tap count: " << tapCount << endl;

        tap();

        aliveBugs=0;
        for (int i = 0; i < bugs.size(); i++)
        {
            if (bugs[i]-> isAlive())
            {
                aliveBugs++;
            }
        }

        cout << "Alive bugs: " << aliveBugs << endl;

        for (int i=0;i<bugs.size();i++)
        {
            if (bugs[i]->isAlive())
            {
                cout << "Bug " << bugs[i]->getId()
                    << " | " << bugs[i]->getType()
                    << " | Position: (" << bugs[i]->getPosition().first
                    << "," << bugs[i]->getPosition().second << ")"
                    << " | Health: " << bugs[i]->getHealth()
                    << endl;
            }

        }
        writeLifeHistoryToFile();

    }
    cout << "GAME OVER" << endl;
    for (int i =0; i<bugs.size();i++)
    {
        if (bugs[i]-> isAlive())
        {
            cout << "Last bug = " << bugs[i]->getId() << endl;
        }
    }


}
void Board:: checkIfTwoBugsAreInSamePosition()
{
    for (int i = 0; i < bugs.size(); i++)
    {
        if (bugs[i]->isAlive())
        {
            for (int j = i+1; j < bugs.size(); j++)
            {
                if (bugs[j]->isAlive())
                {
                    if (bugs[i]->getPosition() == bugs[j]->getPosition())
                    {
                        cout << bugs[i]->getId() << endl;
                        cout << "Is fighting " << endl;
                        cout << bugs[j] ->getId()<< endl;

                        for (int r = 1; r<= 3; r++)
                        {
                            if (!bugs[i]->isAlive() || !bugs[j]->isAlive())
                            {
                                break;
                            }
                            int b1Damage = rand() %6; //random num generator taken from https://www.w3schools.com/cpp/cpp_howto_random_number.asp
                            int b2Damage = rand() %6;

                            bugs[i]->setHealth(bugs[i]->getHealth() - b1Damage);
                            bugs[j]->setHealth(bugs[j]->getHealth() - b2Damage);

                            cout << "Round : " << r << endl;
                            cout << "Bug : " << bugs[i]->getId() << " takes " << b1Damage << " damage" << endl;
                            cout << "Bug : " << bugs[j]->getId() << " takes" << b2Damage << " damage" << endl;

                            if (bugs[i]->getHealth() <=0)
                            {
                                bugs[i]-> setAlive(false);
                                cout << "Bug:  " << bugs[i]->getId() << "died" << endl;
                            }
                            if (bugs[j]->getHealth() <=0)
                            {
                                bugs[j]-> setAlive(false);
                                cout << "Bug : " << bugs[j]->getId() << "died" << endl;
                            }

                        }
                        break;
                    }
                }
            }
        }
    }
}


Board::~Board() {
    for (int i = 0; i < bugs.size(); i++) {
        delete this->bugs[i];
    }
}