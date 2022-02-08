// cashier.h
#include <string>
#pragma once

using namespace std; 

const double SALES_TAX = 0.06;  
class Cashier
{
    string date; 
    int quantity; 
    string isbn; 
    string title;
    double price; 
    double total; 
    
    public:
        void pickItems();
        void displayTicket();
        double calcSubTotal();
        double calcSalesTax();
        double calculateTotal();
};