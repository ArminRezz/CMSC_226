#include <iostream>
#include "bookinfo.h"

using namespace std;

// Book constructor - creates a book object
Bookinfo::Bookinfo(string i, string t, string a,string p, string date, int qty, double w, double r) {
    isbn = i; 
    title = t; 
    author = a; 
    publisher = p; 
    dateAdded = date; 
    quantityOnHand = qty; 
    wholesaleCost = w; 
    retailPrice = r; 
}

// displays information about any given book
void Bookinfo::displayBookInfo() {
    cout << "\n**************************************************\n" << endl;
    cout << "\tSerendipity Booksellers" << endl; 
    cout << "\tBook Information\n" << endl;  
    cout << "ISBN:" << isbn << endl; 
    cout << "Title:" << title << endl; 
    cout << "Author:" << author << endl; 
    cout << "Publisher:" << publisher << endl; 
    cout << "Date Added:" << dateAdded << endl; 
    cout << "Quantity-On-Hand:" << quantityOnHand << endl; 
    cout << "Wholesale Cost:" << wholesaleCost << endl; 
    cout << "Retail Price:" << retailPrice << endl; 
    cout << "\n**************************************************\n" << endl;
}
 