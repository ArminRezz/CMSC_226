// cashier.h
#include <string>
#pragma once
using namespace std; 

extern const double SALES_TAX = 0.06;  
extern string date; 
extern int quantity; 
extern string isbn; 
extern string title;
extern double price; 
extern double total; 

extern void cashier();
extern void displayTicket();
extern double calcSubTotal();
extern double calcSalesTax();
extern double calculateTotal();
