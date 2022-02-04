#include <iostream>
#include "reports.h"
using namespace std;

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
    
    getUserChoice();

    cout << "\n**************************************************\n" << endl;
}

void Reports::getUserChoice() {

    cout << "Enter your choice: " << endl;
    int choice = 0;
    cin >> choice; 

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
        default:
            break;
    }

}

void Reports::inventoryListing() {
    return; 
}
void Reports::inventoryWholesaleValue() {
    return; 
}
void Reports::inventoryRetailValue() {
    return; 
}
void Reports::listingByQuantity() {
    return; 
}
void Reports::listingByCost() {
    return; 
}
void Reports::listingByAge() {
    return; 
}
void Reports::returnToMainMenu() {
    return; 
}
 