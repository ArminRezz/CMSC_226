/******************************************************************
** Program: Programming Project 4: Cashier.cpp
** Description: Get's user purchasing info, displays purchase ticket
** Course: CMSC226 CRN 36331
** Professor: Ping-Wei Tsai
** Student: Armin Rezaiyan-Nojani
** Due Date: 02/14/22
******************************************************************/

#include "cashier.h"

const double SALES_TAX = 0.06;
const int ARRAY_SIZE = 20;  

string date; 
int quantity; 
string isbn; 
string title;
double price; 
double total; 

// calculates subtotal for purchase
double calcSubTotal() {
    return price * quantity; 
}

// claculates sales tax in dollars for purchase
double calcSalesTax() {
    return calcSubTotal() * SALES_TAX; 
}

// calculates total for purchase 
double calculateTotal() {
    return calcSubTotal() + calcSalesTax();
}

// gathers user purchase information 
void cashier() {

    cout << "\n**************************************************\n" << endl;
    cout << "Serendipity Booksellers" << endl; 
    cout << "\tCashier Module" << endl;

    // isbn auto lookup  
    char reEnter; 
    int i; 
    do {
        cout << "Enter ISBN:";   
        cin >> isbn;
        for (i = 0; i < ARRAY_SIZE; i++) {
            if (isbn == isbnArr[i]) {
                cout << "Book title: " << bookTitles[i] << endl;
                cout << "Price: " << retailPrice[i] << endl;
                i = ARRAY_SIZE+1;
            } 
        }
        if (i == ARRAY_SIZE+1) {
            cout << "That book could not be found!" << endl; 
            cout << "Do you want to re-enter the number? (y/n): " << endl;
        }
    } while (reEnter == 'y' || reEnter == 'Y'); 

    cout << "Enter Quantity: " << endl;
    cin >> quantity; 

    // checking and adjusting quantity
    if (quantityOnHand[i] > quantity) {
        cout << "Not enough books available!" << endl;
        return; 
    } else {
        quantityOnHand[i] -= quantity; 
    }

    cout << "\n**************************************************\n" << endl;
    
    displayTicket();
}

// Displays purchase ticket and asks user if they want to do another transaction 
void displayTicket() {

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