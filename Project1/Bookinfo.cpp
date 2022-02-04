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
 