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
        Bookinfo(string i, string t, string a,string p, string date, int qty, double w, double r);
        void displayBookInfo();
};
