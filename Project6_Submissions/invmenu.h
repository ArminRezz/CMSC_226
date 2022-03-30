#pragma once
#include <iostream>
#include <iomanip>
#include <cctype> 

using namespace std; 

extern char bookTitles[][51];
extern char isbnArr[][14];
extern char author[][31];
extern char publisher[][31];
extern char dateAdded[][11];
extern int quantityOnHand[];
extern double wholesaleCost[];
extern double retailPrice[];

void invMenu();
void handleUser(); 
void lookUpBook();
void addBook();
void editBook();
void deleteBook();
int findBookIndex(char*);
void strUpper(char*);


