#pragma once
#include "bookinfo.h"
using namespace std; 

const int ARRAY_SIZE = 20;

extern string isbnArr[ARRAY_SIZE]; 
extern string bookTitles[ARRAY_SIZE]; 
extern string author[ARRAY_SIZE]; 
extern string publisher[ARRAY_SIZE];
extern string dateAdded[ARRAY_SIZE];
extern int quantityOnHand[ARRAY_SIZE]; 
extern double wholesaleCost[ARRAY_SIZE];
extern double retailPrice[ARRAY_SIZE];

extern void invMenu();
extern void handleUser(); 
extern void lookUpBook();
extern void addBook();
extern void editBook();
extern void deleteBook();
extern int findBookIndex(string title);

