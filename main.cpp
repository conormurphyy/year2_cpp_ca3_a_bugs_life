#include <iostream>

#include "Board.h"
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
void mainMenu();

int main() {
    Board board(10,10);
    board.loadBugs();

    mainMenu();

    int choice;
    cin >> choice;
    switch (choice) {
        case 1:
            board.displayAllBugs();
        case 2:
            int id;
            cout << "Enter ID to get a bug by it's ID" << " ";
            cin >> id;
            board.GetBugByID(id);
        default:
            cout << "Invalid choice" << " ";

    }
}

void mainMenu() {
    cout << "Enter 1 to display all bugs" << " ";
    cout << "Enter 2 to get a bug by it's ID" << " ";


}