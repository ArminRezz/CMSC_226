// invmenu.h
#include <string>
#pragma once

using namespace std; 

class Reports
{
    public:
        void displayReportsMenu();
        void getUserChoice();
        void inventoryListing();
        void inventoryWholesaleValue();
        void inventoryRetailValue();
        void listingByQuantity();
        void listingByCost();
        void listingByAge();
        void returnToMainMenu();

};

