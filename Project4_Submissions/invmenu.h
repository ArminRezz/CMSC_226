// invmenu.h
#include <string>
#include "bookinfo.h"
#pragma once
using namespace std; 

const ARRAY_SIZE = 20;
class Invmenu
{
    string isbn[ARRAY_SIZE]; 
    string title[ARRAY_SIZE]; 
    string author[ARRAY_SIZE]; 
    string publisher[ARRAY_SIZE];
    string dateAdded[ARRAY_SIZE];
    int quantityOnHand[ARRAY_SIZE]; 
    double wholesaleCost[ARRAY_SIZE];
    double retailPrice[ARRAY_SIZE]; 

    public:
        void invMenu();
        void handleUserChoice(); 
        void lookUpBook();
        void addBook();
        void editBook();
        void deleteBook();
        int findBookIndex(string title);
};

