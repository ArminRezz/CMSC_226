#include <iostream>
#include "reports.h"
using namespace std;

// Displays menu options for reports
void Reports::displayReportsMenu() {
    cout << "\n**************************************************\n" << endl;
    cout << "Serendipity Booksellers" << endl; 
    cout << "\tReports\n" << endl; 
    cout << "1. Inventory Listing" << endl; 
    cout << "2. Inventory Wholesale Value" << endl; 
    cout << "3. Inventory Retail Value" << endl; 
    cout << "4. Listing by Quantity" << endl; 
    cout << "5. Listing by Cost" << endl; 
    cout << "6. Listing by Age" << endl; 
    cout << "7. Return to Main Menu\n" << endl; 
    
    handleUserChoice();

    cout << "\n**************************************************\n" << endl;
}

// Gets user selection and reroutes to corresponding function
void Reports::handleUserChoice() {

    int choice = 0; 
    cout << "Enter your choice: ";
    cin >> choice;
    while (choice <= 0 || choice > 7) {
        cout << "Please enter number in range 1 - 7" << endl;
        cout << "Enter your choice: "; 
        cin >> choice; 
    }
    cout << "You chose option " << choice << endl; 

     switch(choice) {
        case 1: 
            //inventoryListing();
            break;
        case 2:
            //inventoryWholesaleValue();
            break; 
        case 3:
            //inventoryRetailValue();
            break; 
        case 4:
            //listingByQuantity();
            break; 
        case 5:
            //listingByCost()
            break;
        case 6:
            //listingByAge()
            break;
        case 7:
            break;
    }

}

void Reports::repListing() {
    return; 
}
void Reports::repWholesale() {
    return; 
}
void Reports::repRetail() {
    return; 
}
void Reports::repQty() {
    return; 
}
void Reports::repCost() {
    return; 
}
void Reports::repAge() {
    return; 
}