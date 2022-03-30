/******************************************************************
** Program: Programming Project 4: Invmenu.cpp
** Description: Displays Inventory Menu, recieves and validates user input
** Course: CMSC226 CRN 36331
** Professor: Ping-Wei Tsai
** Student: Armin Rezaiyan-Nojani
** Due Date: 02/14/22
******************************************************************/
#include "invmenu.h"
#include "bookinfo.h"

const int ARRAY_SIZE = 20;
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
    char title[51];
    cin.getline(title, 51);
    cin.ignore();
    
    int row; 
    for (row = 0; row < ARRAY_SIZE; row++) {
        if (strstr(bookTitles[row], title)){
            bookInfo(isbnArr[row], bookTitles[row], author[row], publisher[row], dateAdded[row], quantityOnHand[row], wholesaleCost[row], retailPrice[row]);
        }
    }
    if (row == ARRAY_SIZE-1) {
        cout << "That book was not found!" << endl;
    }
    return;
}

void addBook() {
    cout << "You selected add book." << endl;

    // find empty space in inventory
    int i; 
    for (i = 0; i < ARRAY_SIZE; i++) {
        if (bookTitles[i][0] == 0) {
            cout << "Book title: " << endl;
            cin.ignore();
            cin.getline(bookTitles[i], 51);
            strUpper(bookTitles[i]);
            
            cout << "ISBN number: " << endl;
            cin.getline(isbnArr[i], 14);
            strUpper(isbnArr[i]);

            cout << "Author’s name: " << endl;
            cin.getline(author[i], 31);
            strUpper(author[i]);

            cout << "Publisher’s name: " << endl;
            cin.getline(publisher[i], 31);

            cout << "The date the book was added to the inventory: " << endl;
            cin.getline(dateAdded[i], 11);

            cout << "The quantity of the book being added: " << endl;
            cin >> quantityOnHand[i];
            cout << "The wholesale cost of the book: " << endl;
            cin >> wholesaleCost[i];
            cout << "The retail price of the book: " << endl;
            cin >> retailPrice[i];
            i = ARRAY_SIZE;
        }
    }
    if (i == ARRAY_SIZE-1) {
        cout << "Sorry, no more space in out inventory, thanks for using our bookstore!" << endl;
    }
    return;
}

void editBook() {
    // get book bookTitles
    cout << "You selected edit book." << endl;
    cout << "Enter book title: " << endl;
    char title[51];
    cin.getline(title, 51);

    // find book
    int index = findBookIndex(title);

    if (index == -1) {
        cout << "Book was not found!" << endl;
    } else {
        bookInfo(isbnArr[index], bookTitles[index], author[index], publisher[index], dateAdded[index], quantityOnHand[index], wholesaleCost[index], retailPrice[index]);
        
        cout << "Which fields would you like to change: " << endl;
        string field; 
        cin >> field;

        if (field == "isbn") {
            cout << "Enter new ISBN: ";
            cin.ignore();
            cin.getline(isbnArr[index], 14);
            strUpper(isbnArr[index]);
        }
        else if (field == "title") {
            cout << "Enter new title: ";
            cin.ignore();
            cin.getline(bookTitles[index], 51);
            strUpper(bookTitles[index]);
        }
        else if (field == "author") {
            cout << "Enter new author: ";
            cin.ignore();
            cin.getline(author[index], 31);
            strUpper(author[index]);
        }
        else if (field == "publisher") {
            cout << "Enter new publisher: ";
            cin.ignore();
            cin.getline(publisher[index], 31);
            strUpper(publisher[index]);
        }
        else if (field == "date"){
            cout << "Enter new date: ";
            cin.ignore();
            cin.getline(dateAdded[index], 11);
        }
        else if (field == "quantity") {
            cout << "Enter new quantity: ";
            cin >> quantityOnHand[index];
        }
        else if (field == "wholesale") {
            cout << "Enter new wholesale: ";
            cin >> wholesaleCost[index];
        }
        else if (field == "retail") {
            cout << "Enter new retail: ";
            cin >> retailPrice[index];
        } else {
            cout << "That input was invalid!";
        }
    }
    return;
}

void deleteBook() {
    // get book bookTitles
    cout << "You selected edit book." << endl;
    cout << "Enter book title: " << endl;
    cin.ignore();
    char title[51];
    cin.getline(title, 51);

    // find book
    int index = findBookIndex(title);

    if (index == -1) {
        cout << "Book was not found!" << endl;
    } else {
        bookInfo(isbnArr[index], bookTitles[index], author[index], publisher[index], dateAdded[index], quantityOnHand[index], wholesaleCost[index], retailPrice[index]);
        cout << "Are you sure you want to remove this book? (y/n): " << endl;
        char remove; 
        cin >> remove; 

        if (remove == 'Y' || remove == 'y' ) {
            strcpy(bookTitles[index], "");
            strcpy(isbnArr[index], "");
            strcpy(author[index], "");
            strcpy(publisher[index], "");
            strcpy(dateAdded[index], "");
            quantityOnHand[index] = 0;
            wholesaleCost[index] = 0.0;
            retailPrice[index] = 0.0;
            cout << "Book succsessfully deleted!" << endl; 
        }
    }
    return;
}

int findBookIndex(char* title) {
    int index = -1;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (strstr(bookTitles[i], title)) {
            index = i; 
            i = ARRAY_SIZE;
        }
    }
    return index;
}

void strUpper(char* str) {
    while (*str != 0) {
        *str = toupper(*str);
        str++;
    }
}