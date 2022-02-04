#include <iostream>
#include "Cashier.cpp"
#include "Invmenu.cpp"
#include "Reports.cpp"
#include "Bookinfo.cpp"

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

    Cashier order; 
    Invmenu inventory; 
    Reports report; 

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

        cout << "You chose option " << choice << endl; 
        cout << "\n**************************************************\n" << endl;

        switch(choice) {
        case 1: 
            order.pickItems(); 
            break;
        case 2:
            inventory.displayInventoryMenu();
            break; 
        case 3:
            report.displayReportsMenu();
            break;
        case 4:
            cout << "Thank you for coming to my store!!!" << endl; 
            cout << "\n**************************************************\n" << endl;
            break; 
        }

    } while(choice != 4);
    
    return 0; 
}