/******************************************************************
** Program: Programming Project 4: Mainmenu.cpp
** Description: Displays Main Menu, recieves and validates user input, branches to other modules
** Course: CMSC226 CRN 36331
** Professor: Ping-Wei Tsai
** Student: Armin Rezaiyan-Nojani
** Due Date: 02/14/22
******************************************************************/

#include "cashier.h"
#include "bookinfo.h"
#include "invmenu.h"
#include "reports.h"

#include <iostream>

using namespace std; 

void displayMainMenu() {
    cout << "\n**************************************************\n" << endl;
    cout << "Serendipity Booksellers" << endl; 
    cout << "\tMain Menu\n" << endl; 
    cout << "1. Cashier Module" << endl; 
    cout << "2. Inventory Database Module" << endl; 
    cout << "3. Report Module" << endl; 
    cout << "4. Exit" << endl; 
}

int main() {

    int choice = 0;
    do {

        displayMainMenu(); 
        cout << "Enter your choice: ";
        cin >> choice;
        while (choice <= 0 || choice > 4) {
            cout << "Please enter number in range 1 - 4" << endl;
            cout << "Enter your choice: "; 
            cin >> choice; 
        }

        cout << "\nYou chose option " << choice << endl; 
        cout << "\n**************************************************\n" << endl;

        switch(choice) {
        case 1: 
            cashier(); 
            break;
        case 2:
            invMenu();
            break; 
        case 3:
            reports();
            break;
        case 4:
            cout << "Thank you for coming to my store!!!" << endl; 
            cout << "\n**************************************************\n" << endl;
            break; 
        }

    } while(choice != 4);
    
    return 0; 
}