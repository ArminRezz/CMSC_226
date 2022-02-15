/******************************************************************
** Program: Programming Project 2: Cashier.cpp
** Description: Get's user purchasing info, displays purchase ticket
** Course: CMSC226 CRN 36331
** Professor: Ping-Wei Tsai
** Student: Armin Rezaiyan-Nojani
** Due Date: 02/14/22
******************************************************************/

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
    return calcSubTotal() * SALES_TAX; 
}

// calculates total for purchase 
double Cashier::calculateTotal() {
    return calcSubTotal() + calcSalesTax();
}

// gathers user purchase information 
void Cashier::cashier() {
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

     // Display reciept/ticket with all the information
    cout << "Serendipity Book Sellers\n" << endl; 
    cout << "Date: " << date << "\n\n"; 
    cout << left << setw(5) << "Qty" << setw(10) << "ISBN" << setw(20) << "Title" << setw(10) << "Price" << setw(10) << "Total" << endl;
    cout << left << setw(5) << quantity << setw(10) << isbn << setw(20) << title << setw(10) << showpoint << fixed << setprecision(2) << price << setw(10) << calcSubTotal() << endl; 
    cout << "___________________________________________________________\n" << endl; 
    cout << "\tSubtotal: " << calcSubTotal() << endl; 
    cout << "\tTax: " << showpoint << setprecision(2) << calcSalesTax() << endl; 
    cout << "\tTotal: " << showpoint << setprecision(2) << calculateTotal() << endl; 
    cout << "Thank You for Shopping at Serendipity!" << endl; 

    // asks user if they want to start a new transaction
    char newTrans;
    do {
        cout << "Would you like to start a new transaction? " << endl; 
        cout << "Please enter one of the following | Y, y, N, n | : " << endl;
        cin >> newTrans; 
    } while ((newTrans != 'Y') && (newTrans != 'y') && (newTrans != 'N') && (newTrans != 'n'));

    if (newTrans == 'Y' || newTrans == 'y' ) {
        cout << "\n**************************************************\n" << endl;
        cashier();
    }  
    return;

   
}