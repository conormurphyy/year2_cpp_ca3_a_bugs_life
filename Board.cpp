//
// Created by conor on 23/04/2026.
//

#include "Board.h"

#include "Bug.h"
#include <iostream>
#include <sstream>

#include "Crawler.h"
#include "Hopper.h"
using namespace std;

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
        else {
            cout << "Error finding bug type" << endl;
        }

    }
}

void Board::displayAllBugs() {
    for (int i = 0; i < bugs.size(); i++) {
        cout << bugs[i]->getId() << " ";
        cout << bugs[i]->getPosition().first << " ";
        cout << bugs[i]->getPosition().second << " ";
        cout << bugs[i]->getHealth() << " ";
        cout << endl;
    }
}

Board::~Board() {
    for (int i = 0; i < bugs.size(); i++) {
        delete this->bugs[i];
    }
}