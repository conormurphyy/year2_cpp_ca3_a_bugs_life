#include <iostream>

#include "Board.h"
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
void mainMenu();

int main() {
    Board board(10,10);
    board.loadBugs();
    while (true) {


    mainMenu();

    int choice;
    cin >> choice;
    switch (choice) {
        case 1:
            board.displayAllBugs();
            break;
        case 2:
            int id;
            cout << "Enter ID to get a bug by it's ID" << " ";
            cin >> id;
            board.GetBugByID(id);
            break;
        case 3:
            board.displayAllCells();
            break;
        case 4:
            board.tap();
            cout << "Bugs have been tapped" << "\n";
            break;
        case 5:
            board.displayHistoryOfAllBugs();
            break;
        case 6:
            board.runSimulation();
        case 0:
            exit(0);
        default:
            cout << "Invalid choice" << " ";
            break;
    }
    }
}

void mainMenu() {
    cout << "Enter 1 to display all bugs" << "\n";
    cout << "Enter 2 to get a bug by it's ID" << "\n";
    cout << "Enter 3 to display all cells" << "\n";
    cout << "Enter 4 to tap a bug" << "\n";
    cout << "Enter 5 to see the life history of bugs" << "\n";
    cout << "Enter 6 to run a simulation" << "\n";
    cout << "Enter 0 to exit" << "\n";

}