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
        // default constructor
        Bookinfo();
        //isbn, title, author, publisher, dateAdded, quantityOnHand, wholesaleCost, retailPrice
        Bookinfo(string i, string t, string a, string p, string d, int q, double w, double r);
        void bookInfo();
};

string string string string string int double double  