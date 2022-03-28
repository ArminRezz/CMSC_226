// cashier.h
#pragma once

#include <iostream>
#include <iomanip>

using namespace std; 

extern string isbnArr[]; 
extern string bookTitles[]; 
extern string author[]; 
extern string publisher[];
extern string dateAdded[];
extern int quantityOnHand[]; 
extern double wholesaleCost[];
extern double retailPrice[];

void cashier();
void displayTicket();
double calcSubTotal();
double calcSalesTax();
double calculateTotal();
