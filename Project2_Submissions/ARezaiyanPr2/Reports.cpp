/******************************************************************
** Program: Programming Project 2: Reports.cpp
** Description: Displays Inventory Menu, recieves and validates user input
** Course: CMSC226 CRN 36331
** Professor: Ping-Wei Tsai
** Student: Armin Rezaiyan-Nojani
** Due Date: 02/14/22
******************************************************************/

#include <iostream>
using namespace std; 

int main() {

    int choice = 0;
    do {
        // Display reports Menu
        cout << "Serendipity Booksellers" << endl; 
        cout << "\tReports\n" << endl; 
        cout << "1. Inventory Listing" << endl; 
        cout << "2. Inventory Wholesale Value" << endl; 
        cout << "3. Inventory Retail Value" << endl; 
        cout << "4. Listing by Quantity" << endl; 
        cout << "5. Listing by Cost" << endl; 
        cout << "6. Listing by Age" << endl; 
        cout << "7. Return to Main Menu\n" << endl; 

        // Get VALID user input
        cout << "Enter your choice: ";
        cin >> choice;
        while (choice <= 0 || choice > 7) {
            cout << "Please enter number in range 1 - 7" << endl;
            cout << "Enter your choice: "; 
            cin >> choice; 
        }

    } while (choice != 7);
    
    return 0; 
}

