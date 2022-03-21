// invmenu.h
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

void reports();
void handleUserChoice();
void repListing();
void repWholesale();
void repRetail();
void repQty();
void repCost();
void repAge();
void selectionSort(double[]);
void selectionSort(int[]);

