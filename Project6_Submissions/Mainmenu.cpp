/******************************************************************
** Program: Programming Project 4: Mainmenu.cpp
** Description: Displays Main Menu, recieves and validates user input, branches to other modules
** Course: CMSC226 CRN 36331
** Professor: Ping-Wei Tsai
** Student: Armin Rezaiyan-Nojani
** Due Date: 02/14/22
******************************************************************/
#include <iostream>
#include "invmenu.h"
#include "cashier.h"
#include "bookinfo.h"
#include "reports.h"

using namespace std; 

const int ARRAY_SIZE = 20; 

extern char isbnArr[ARRAY_SIZE][14];
extern char bookTitles[ARRAY_SIZE][51];
extern char author[ARRAY_SIZE][31];
extern char publisher[ARRAY_SIZE]31];
extern char dateAdded[ARRAY_SIZE][11];
extern int quantityOnHand[ARRAY_SIZE]; 
extern double wholesaleCost[ARRAY_SIZE];
extern double retailPrice[ARRAY_SIZE];

void MainMenu();

int main() {

   MainMenu();
   return 0; 
}

void MainMenu() {

    int choice = 0;
    do {

        cout << "\n**************************************************\n" << endl;
        cout << "Serendipity Booksellers" << endl; 
        cout << "\tMain Menu\n" << endl; 
        cout << "1. Cashier Module" << endl; 
        cout << "2. Inventory Database Module" << endl; 
        cout << "3. Report Module" << endl; 
        cout << "4. Exit" << endl; 
        cout << "\n**************************************************\n" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        while (choice <= 0 || choice > 4) {
            cout << "Please enter number in range 1 - 4" << endl;
            cout << "Enter your choice: "; 
            cin >> choice; 
        }

        cout << "\nYou chose option " << choice << endl; 

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
}