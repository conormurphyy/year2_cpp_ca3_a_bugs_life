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

void Board::loadBugs() {
    ifstream fin("bugs.txt");
    if (fin) {
        string line;
        std::stringstream test(line);
        std:string semicolon;
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
    else {
        cout << "No file found" << endl;
    }
}