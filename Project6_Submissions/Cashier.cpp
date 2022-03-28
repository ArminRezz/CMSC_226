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

int bookIndex[ARRAY_SIZE];
int numOfBooks; 
string isbn; 
int quantity[ARRAY_SIZE]; 

// calculates subtotal for purchase
double calcSubTotal() {
    int total = 0; 
    for (int i = 0; i < numOfBooks; i++) {
        total += retailPrice[i] * quantity[i];
    }
    return total; 
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

    char anotherBook = 'Y'; 
    numOfBooks = 0; 
    while (anotherBook == 'Y' || anotherBook == 'y') {
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
                    bookIndex[numOfBooks] = i;
                    numOfBooks++; 
                    i = ARRAY_SIZE+1;
                } 
            }
            if (i == ARRAY_SIZE+1) {
                cout << "That book could not be found!" << endl; 
                cout << "Do you want to re-enter the number? (y/n): " << endl;
            }
        } while (reEnter == 'y' || reEnter == 'Y'); 

        // quantity checking and adjusting
        cout << "Enter Quantity: " << endl;
        cin >> quantity[numOfBooks-1]; 

        if (quantityOnHand[bookIndex[numOfBooks-1]] < quantity[numOfBooks-1]) {
            cout << "Not enough books available!" << endl;
            return; 
        } else {
            quantityOnHand[bookIndex[numOfBooks-1]] -= quantity[numOfBooks-1]; 
        }

        cout << "Do you want to add another book? (y/n) : " << endl; 
        cin >> anotherBook; 
    }

    cout << "\n**************************************************\n" << endl;
    
    displayTicket();
}

// Displays purchase ticket and asks user if they want to do another transaction 
void displayTicket() {

    // Display reciept/ticket with all the information
    cout << "Serendipity Book Sellers\n" << endl; 
    cout << left << setw(5) << "Qty" << setw(10) << "ISBN" << setw(20) << "Title" << setw(10) << "Price" << setw(10) << "Total\n" << endl;

    for (int i = 0; i < numOfBooks; i++) {
        int qty = quantity[bookIndex[i]]; 
        cout << endl; 
        cout << left << setw(5) << qty << setw(10) << isbnArr[bookIndex[i]] << setw(20) << bookTitles[bookIndex[i]]; 
        cout << left << setw(10) << showpoint << fixed << setprecision(2) << retailPrice[bookIndex[i]] << setw(10) << retailPrice[bookIndex[i]] * qty << endl; 
    }
    
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