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
#include "Bookinfo.cpp"
#include "invmenu.h"

using namespace std;

// Displays menu options for inventory
void Invmenu::invMenu() {  
    cout << "\n**************************************************\n" << endl;
    cout << "Serendipity Booksellers" << endl; 
    cout << "Inventory Database\n" << endl; 
    cout << "1. Look Up a Book" << endl; 
    cout << "2. Add a Book" << endl; 
    cout << "3. Edit a Book’s Record" << endl; 
    cout << "4. Delete a Book" << endl; 
    cout << "5. Return to the Main Menu" << endl; 
    cout << "\n**************************************************\n" << endl;
    handleUserChoice();
}

// Gets user selection and reroutes to corresponding function
void Invmenu::handleUserChoice() {

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

void Invmenu::lookUpBook() {
    cout << "You selected Look up book." << endl;
    cout << "Enter title of book: " << endl;
    string title;
    cin >> title;

    // find book index 
    int index = findBookIndex(title);

    if (bookTitle[index].compare("") == 0) {
        cout << "Book was not found!" << endl;
    } else {
        Bookinfo book;
        book.bookInfo(isbn[index], bookTitle[index], author[index], publisher[index], dateAdded[index], quantityOnHand[index], wholesaleCost[index], retailPrice[index]);
    }
    return;
}

void Invmenu::addBook() {
    cout << "You selected add book." << endl;

    // find empty space in inventory
    int index = findBookIndex("");

    // Get book information
    if (index != 0 && index < ARRAY_SIZE) {
        cout << "Book title: " << endl;
        cin >> bookTitle[index];
        cout << "ISBN number: " << endl;
        cin >> isbn[index];
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

void Invmenu::editBook() {
    // get book title
    cout << "You selected edit book." << endl;
    cout << "Enter title of book: " << endl;
    string title;
    cin >> title;

    // find book
    int index = findBookIndex(title);

    if (index == 0) {
        cout << "Book was not found!" << endl;
    } else {
        Bookinfo book;
        book.bookInfo(isbn[index], bookTitle[index], author[index], publisher[index], dateAdded[index], quantityOnHand[index], wholesaleCost[index], retailPrice[index]);
        
        cout << "Which fields would you like to change: " << endl;
        string field; 
        cin >> field;

        switch(field) {
            case "isbn":
                cout << "Enter new isbn: " << endl;
                cin >> isbn[index];
                break; 
            case "title":
                cout << "Enter new title: " << endl;
                cin >> bookTitle[index];
                break; 
            case "author":
                cout << "Enter new author: " << endl;
                cin >> author[index];
                break; 
            case "publisher":
                cout << "Enter new publisher: " << endl;
                cin >> publisher[index];
                break;
            case "date":
                cout << "Enter new date: " << endl;
                cin >> dateAdded[index];
                break;
            case "quantity":
                cout << "Enter new quantity: " << endl;
                cin >> quantityOnHand[index];
                break;
            case "wholesale": 
                cout << "Enter new wholesale: " << endl;
                cin >> wholesaleCost[index];
                break;
            case "retail": 
                cout << "Enter new retail: " << endl;
                cin >> retailPrice[index];
                break;
            default: 
                cout << "That input was invalid!" << endl;
                break; 
        }
    }
    return;
}

void Invmenu::deleteBook() {
    // get title
    cout << "You selected delete book." << endl;
    cout << "Enter title of book you want to remove: " << endl; 
    string title;
    cin >> title; 

    // Find book
    int index = findBookIndex(title);

    // Get book information
    if (index < ARRAY_SIZE) {
        Bookinfo book; 
        book.bookInfo(isbn[index], bookTitle[index], author[index], publisher[index], dateAdded[index], quantityOnHand[index], wholesaleCost[index], retailPrice[index]);
    } else {
        cout << "Sorry, could not find that book in the inventory!"
    }

    // ask user if they want to remove book, if yes, remove book, if no, don't change anything
    cout << "Are you sure you want to remove this book? (y/n): " << endl;
    cin >> remove; 
    if (remove == 'Y' || remove == 'y' ) {
        isbn[index] = 
        bookTitle[index] = "";
        author[index] = ""; 
        publisher[index] = "";
        dateAdded[index] = "";
        quantityOnHand[index] = null;
        wholesaleCost[index] = null;
        retailPrice[index] = null;
    }
    cout << "Book succsessfully deleted!" << endl; 
    return;
}

int findBookIndex(string title) {
    int index = 0;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (bookTitle[i].compare(title) == 0) {
            index = i; 
            i = ARRAY_SIZE;
        }
    }
    return index;
}