#include <iostream>
#include <iomanip>
#include <string> 
#include "cashier.h"

using namespace std; 

double Cashier::calcSubTotal() {
    return price * quantity; 
}

double Cashier::calcSalesTax() {
    return calcSubTotal() * 0.06; 
}

double Cashier::calculateTotal() {
    return calcSubTotal() + calcSalesTax();
}

void Cashier::pickItems() {
    cout << "\n**************************************************\n" << endl;
    cout << "Serendipity Booksellers" << endl; 
    cout << "\tCashier Module" << endl; 
    cout << "Date: "; 
    cin >> date; 
    cout << "Quantity of Book:";   
    cin >> quantity;
    cout << "ISBN:";   
    cin >> isbn;
    cout << "Title:";   
    cin >> title;
    cout << "Price:";   
    cin >> price;
    cout << "\n**************************************************\n" << endl;
}

void Cashier::displayTicket() {
    cout << "\n**************************************************\n" << endl;
    cout << "Serendipity Book Sellers\n" << endl; 
    cout << "Date: " << date << "\n\n"; 
    cout << left << setw(5) << "Qty" << setw(10) << "ISBN" << setw(20) << "Title" << setw(10) << "Price" << setw(10) << "Total" << endl;
    cout << left << setw(5) << quantity << setw(10) << isbn << setw(20) << title << setw(10) << price << setw(10) << calculateTotal() << endl; 
    cout << "___________________________________________________________\n" << endl; 
    cout << "\tSubtotal: " << calcSubTotal() << endl; 
    cout << "\tTax: " << showpoint << setprecision(2) << calcSalesTax() << endl; 
    cout << "\tTotal: " << showpoint << setprecision(2) << calculateTotal() << endl; 
    cout << "Thank You for Shopping at Serendipity!" << endl; 
    cout << "\n**************************************************\n" << endl;
}