#include <iostream>

#include "Board/Board.h"
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
            break;
        case 0:
            exit(0);
        default:
            cout << "Invalid choice" << " ";
            break;
    }
    }
}

void mainMenu() {
    cout << "\n";
    cout << "===========================================" << endl;
    cout << "          A Bugs Life Menu" << endl;
    cout << "===========================================" << endl;
    cout << "1. Display all bugs" << "\n";
    cout << "2. Get a bug by it's ID" << "\n";
    cout << "3. Display all cells" << "\n";
    cout << "4. Tap a bug" << "\n";
    cout << "5. See the life history of bugs" << "\n";
    cout << "6. Run a simulation" << "\n";
    cout << "0. Exit" << "\n";
    cout << "===========================================" << endl;
    cout << "Enter Your Choice Below" << endl;


}