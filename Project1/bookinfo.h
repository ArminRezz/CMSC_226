// invmenu.h
#include <string>
#pragma once

using namespace std; 

class Bookinfo
{
    string isbn; 
    string title; 
    string author; 
    string publisher;
    string dateAdded;
    int quantityOnHand; 
    double wholesaleCost;
    double retailPrice; 
    
    public:
        Bookinfo();
        void displayBookInfo();
};
