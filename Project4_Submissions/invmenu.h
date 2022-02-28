#pragma once
#include <iostream>
#include <string>
using namespace std; 

extern string isbnArr[]; 
extern string bookTitles[]; 
extern string author[]; 
extern string publisher[];
extern string dateAdded[];
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

