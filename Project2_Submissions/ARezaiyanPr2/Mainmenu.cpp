/******************************************************************
** Program: Programming Project 2: Mainmenu.cpp
** Description: Displays Main Menu, recieves and validates user input, branches to other modules
** Course: CMSC226 CRN 36331
** Professor: Ping-Wei Tsai
** Student: Armin Rezaiyan-Nojani
** Due Date: 02/14/22
******************************************************************/

#include <iostream>

using namespace std; 

int main() {

    int choice; 

     do {

        // Display Main Menu 
        cout << "\n**************************************************\n" << endl;
        cout << "Serendipity Booksellers" << endl; 
        cout << "\tMain Menu\n" << endl; 
        cout << "1. Cashier Module" << endl; 
        cout << "2. Inventory Database Module" << endl; 
        cout << "3. Report Module" << endl; 
        cout << "4. Exit" << endl; 

        // get user input
        cout << "Enter your choice: ";
        cin >> choice;

        // check user input
        while (choice <= 0 || choice > 4) {
            cout << "Please enter number in range 1 - 4" << endl;
            cout << "Enter your choice: "; 
            cin >> choice; 
        }
        cout << "You chose option " << choice << endl; 
        cout << "\n**************************************************\n" << endl;

        // send user to each module
        switch(choice) {
        case 1: 
            cout << "You have chose to enter the Cashier Module." << endl;
            break;
        case 2:
            cout << "You have chose to enter the Inventory Database Module." << endl;
            break; 
        case 3:
            cout << "You have chose to enter the Report Module." << endl;
            break;
        case 4:
            cout << "Thank you for coming to my store!!!" << endl; 
            cout << "\n**************************************************\n" << endl;
            break; 
        }

    } while(choice != 4);

    return 0; 
}