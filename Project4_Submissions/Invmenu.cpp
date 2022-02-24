/******************************************************************
** Program: Programming Project 4: Invmenu.cpp
** Description: Displays Inventory Menu, recieves and validates user input
** Course: CMSC226 CRN 36331
** Professor: Ping-Wei Tsai
** Student: Armin Rezaiyan-Nojani
** Due Date: 02/14/22
******************************************************************/

#include <iostream>
#include <string>
#include "invmenu.h"

using namespace std;

// Displays menu options for inventory
void invMenu() {  
    cout << "\n**************************************************\n" << endl;
    cout << "Serendipity Booksellers" << endl; 
    cout << "Inventory Database\n" << endl; 
    cout << "1. Look Up a Book" << endl; 
    cout << "2. Add a Book" << endl; 
    cout << "3. Edit a Book’s Record" << endl; 
    cout << "4. Delete a Book" << endl; 
    cout << "5. Return to the Main Menu" << endl; 
    cout << "\n**************************************************\n" << endl;
    handleUser();
}

// Gets user selection and reroutes to corresponding function
void handleUser() {

    int choice = 0; 
    cout << "Enter your choice: ";
    cin >> choice;
    while (choice <= 0 || choice > 5) {
        cout << "Please enter number in range 1 - 5" << endl;
        cout << "Enter your choice: "; 
        cin >> choice; 
    }
    cout << "You chose option " << choice << endl; 

    switch(choice) {
        case 1: 
            lookUpBook();
            break;
        case 2:
            addBook();
            break; 
        case 3:
            editBook();
            break; 
        case 4:
            deleteBook();
            break; 
        case 5:
            break;
    }

}

void lookUpBook() {
    cout << "You selected Look up book." << endl;
    cout << "Enter bookTitles of book: " << endl;
    string title;
    cin >> title;

    // find book index 
    int index = findBookIndex(title);

    if (bookTitles[index] == "") {
        cout << "Book was not found!" << endl;
    } else {
        bookInfo(isbnArr[index], bookTitles[index], author[index], publisher[index], dateAdded[index], quantityOnHand[index], wholesaleCost[index], retailPrice[index]);
    }
    return;
}

void addBook() {
    cout << "You selected add book." << endl;

    // find empty space in inventory
    int index = findBookIndex("");

    // Get book information
    if (index != 0 && index < ARRAY_SIZE) {
        cout << "Book title: " << endl;
        cin >> bookTitles[index];
        cout << "isbnArr number: " << endl;
        cin >> isbnArr[index];
        cout << "Author’s name: " << endl;
        cin >> author[index];
        cout << "Publisher’s name: " << endl;
        cin >> publisher[index];
        cout << "The date the book was added to the inventory: " << endl;
        cin >> dateAdded[index];
        cout << "The quantity of the book being added: " << endl;
        cin >> quantityOnHand[index];
        cout << "The wholesale cost of the book: " << endl;
        cin >> wholesaleCost[index];
        cout << "The retail price of the book: " << endl;
        cin >> retailPrice[index];
    } else {
        cout << "Sorry, no more space in out inventory, thanks for using our bookstore!" << endl;
    }
    return;
}

void editBook() {
    // get book bookTitles
    cout << "You selected edit book." << endl;
    cout << "Enter bookTitles of book: " << endl;
    string title;
    cin >> title;

    // find book
    int index = findBookIndex(title);

    if (index == 0) {
        cout << "Book was not found!" << endl;
    } else {
        bookInfo(isbnArr[index], bookTitles[index], author[index], publisher[index], dateAdded[index], quantityOnHand[index], wholesaleCost[index], retailPrice[index]);
        
        cout << "Which fields would you like to change: " << endl;
        string field; 
        cin >> field;

        if (field == "isbn") {
            cout << "Enter new isbnArr: " << endl;
            cin >> isbnArr[index];
        }
        else if (field == "title") {
            cout << "Enter new title: " << endl;
            cin >> bookTitles[index];
        }
        else if (field == "author") {
            cout << "Enter new author: " << endl;
            cin >> author[index];
        }
        else if (field == "publisher") {
            cout << "Enter new publisher: " << endl;
            cin >> publisher[index];
        }
        else if (field == "date"){
            cout << "Enter new date: " << endl;
            cin >> dateAdded[index];
        }
        else if (field == "quantity") {
            cout << "Enter new quantity: " << endl;
            cin >> quantityOnHand[index];
        }
        else if (field == "wholesale") {
            cout << "Enter new wholesale: " << endl;
            cin >> wholesaleCost[index];
        }
        else if (field == "retail") {
            cout << "Enter new retail: " << endl;
            cin >> retailPrice[index];
        } else {
            cout << "That input was invalid!" << endl;
        }
    }
    return;
}

void deleteBook() {
    // get bookTitles
    cout << "You selected delete book." << endl;
    cout << "Enter bookTitles of book you want to remove: " << endl; 
    string title;
    cin >> title; 

    // Find book
    int index = findBookIndex(title);

    // Get book information
    if (index < ARRAY_SIZE) {
        bookInfo(isbnArr[index], bookTitles[index], author[index], publisher[index], dateAdded[index], quantityOnHand[index], wholesaleCost[index], retailPrice[index]);
    } else {
        cout << "Sorry, could not find that book in the inventory!";
    }

    // ask user if they want to remove book, if yes, remove book, if no, don't change anything
    cout << "Are you sure you want to remove this book? (y/n): " << endl;
    char remove; 
    cin >> remove; 

    if (remove == 'Y' || remove == 'y' ) {
        isbnArr[index] = "";
        bookTitles[index] = "";
        author[index] = ""; 
        publisher[index] = "";
        dateAdded[index] = "";
        quantityOnHand[index] = 0;
        wholesaleCost[index] = 0.0;
        retailPrice[index] = 0.0;
    }
    cout << "Book succsessfully deleted!" << endl; 
    return;
}

int findBookIndex(string title) {
    int index = 0;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (bookTitles[i] == title) {
            index = i; 
            i = ARRAY_SIZE;
        }
    }
    return index;
}