/******************************************************************
** Program: Programming Project 2: Bookinfo.cpp
** Description: Displays information about particular book
** Course: CMSC226 CRN 36331
** Professor: Ping-Wei Tsai
** Student: Armin Rezaiyan-Nojani
** Due Date: 02/14/22
******************************************************************/

#include <iostream>
#include "bookinfo.h"

using namespace std;

 // default constructor
Bookinfo::Bookinfo() {
    isbn = "NOT AVAILABLE"; 
    title = "NOT AVAILABLE"; 
    author = "NOT AVAILABLE"; 
    publisher = "NOT AVAILABLE";
    dateAdded = "NOT AVAILABLE";
    quantityOnHand = 0; 
    wholesaleCost = 0.0;
    retailPrice = 0.0; 
}

// all parameter constructor
Bookinfo(string i, string t, string a, string p, string d, int q, double w, double r) {
    isbn = i; 
    title = t; 
    author = a; 
    publisher = p;
    dateAdded = d;
    quantityOnHand = q; 
    wholesaleCost = w;
    retailPrice = r; 
}

// displays information about any given book// displays information about any given book
void Bookinfo::bookInfo() {
    cout << "\n**************************************************\n" << endl;
    cout << "\tSerendipity Booksellers" << endl; 
    cout << "\tBook Information\n" << endl;  
    cout << "ISBN:" << endl; 
    cout << "Title:" << endl; 
    cout << "Author:" << endl; 
    cout << "Publisher:" << endl; 
    cout << "Date Added:" << endl; 
    cout << "Quantity-On-Hand:" << endl; 
    cout << "Wholesale Cost:" << endl; 
    cout << "Retail Price:" << endl; 
    cout << "\n**************************************************\n" << endl;
}
 