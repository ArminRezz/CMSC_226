#include <iostream>
#include <iomanip>
#include <string> 
#include "cashier.h"

using namespace std; 

// calculates subtotal for purchase
double Cashier::calcSubTotal() {
    return price * quantity; 
}

// claculates sales tax in dollars for purchase
double Cashier::calcSalesTax() {
    return calcSubTotal() * 0.06; 
}

// calculates total for purchase 
double Cashier::calculateTotal() {
    return calcSubTotal() + calcSalesTax();
}

// gathers user purchase information 
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
    displayTicket();
}

// Displays purchase ticket and asks user if they want to do another transaction 
void Cashier::displayTicket() {

    // displays reciept of purchase information 
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

    // asks user if they want to start a new transaction
    string newTransaction; 
    cout << "\nWould you like to start a new transaction(y/n): " << endl; 
    cin >> newTransaction;
    while (newTransaction != "Y" || newTransaction != "y" || newTransaction != "N" || newTransaction != "n") {
        cout << "Please enter one of the following | Y, y, N, n |" << endl;
        cout << "Would you like to start a new transaction(y/n): " << endl; 
        cin >> newTransaction; 
    }

    if (newTransaction == "Y" || newTransaction == "y" ) {
        pickItems();
    }

    cout << "\n**************************************************\n" << endl;
}