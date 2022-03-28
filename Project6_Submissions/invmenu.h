#pragma once
#include <iostream>
#include <string>
#include <cctype> 

using namespace std; 

extern char isbnArr[][];
extern char bookTitles[][];
extern char author[][];
extern char publisher[][];
extern char dateAdded[][];
extern int quantityOnHand[]; 
extern double wholesaleCost[];
extern double retailPrice[];

void invMenu();
void handleUser(); 
void lookUpBook();
void addBook();
void editBook();
void deleteBook();
int findBookIndex(string);

