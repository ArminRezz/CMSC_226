// invmenu.h
#pragma once

#include <iostream>
#include <iomanip>

using namespace std; 

extern char isbnArr[][];
extern char bookTitles[][];
extern char author[][];
extern char publisher[][];
extern char dateAdded[][];
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
void printTotal(double[]);  
