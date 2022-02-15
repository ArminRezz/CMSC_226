/******************************************************************
** Program: Programming Project 2: Invmenu.cpp
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
    return;
}
void Invmenu::addBook() {
    cout << "You selected add book." << endl;
    return;
}
void Invmenu::editBook() {
    cout << "You selected edit book." << endl;
    return;
}
void Invmenu::deleteBook() {
    cout << "You selected delete book." << endl;
    return;
}

void addBooksToVector() {
    bookInv.push_back(new BookInfo());
}
void printUsingVector() {
    for(int i=0; i < a.size(); i++) {
        std::cout << a.at(i) << ' ';
}

