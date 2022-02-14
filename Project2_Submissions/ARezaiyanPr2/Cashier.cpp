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

using namespace std; 

int main() {

    // declare variables for purchasing book
    string date; 
    int quantity; 
    string isbn; 
    string title;
    double price; 
    char newTrans; 

    do {
        // Get user input
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

        // calculate subtotal, sales tax, and total
        double subTotal = price * quantity;
        double salesTax = subTotal * 0.06; 
        double total = subTotal + salesTax;

        // Display reciept/ticket with all the information
        cout << "Serendipity Book Sellers\n" << endl; 
        cout << "Date: " << date << "\n\n"; 
        cout << left << setw(5) << "Qty" << setw(10) << "ISBN" << setw(20) << "Title" << setw(10) << "Price" << setw(10) << "Total" << endl;
        cout << left << setw(5) << quantity << setw(10) << isbn << setw(20) << title << setw(10) << showpoint << fixed << setprecision(2) << price << setw(10) << subTotal << endl; 
        cout << "___________________________________________________________\n" << endl; 
        cout << "\tSubtotal: " << subTotal << endl; 
        cout << "\tTax: " << showpoint << setprecision(2) << salesTax << endl; 
        cout << "\tTotal: " << showpoint << setprecision(2) << total << endl; 
        cout << "Thank You for Shopping at Serendipity!" << endl; 

        do {
            cout << "Would you like to start a new transaction? " << endl; 
            cout << "Please enter one of the following | Y, y, N, n | : " << endl;
            cin >> newTrans; 
        } while ((newTrans != 'Y') && (newTrans != 'y') && (newTrans != 'N') && (newTrans != 'n'));

    } while (newTrans != 'N' && newTrans != 'n');

    return 0; 
}