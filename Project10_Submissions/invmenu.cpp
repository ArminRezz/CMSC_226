#include "invmenu.h"
#include "bookdata.h"
#include "bookinfo.h"
#include "strupper.h"

const int SIZE = 20; 
extern BookData books[20];
char input[51];

void invMenu() {

    //declaring choice variable
    int choice = 0;
    while (choice != 5){

        //printing the inventory menu
        cout << "\n  Serendipity Booksellers\n    Inventory Database\n\n";
        cout << "1.  Look Up a Book\n2.  Add a Book\n3.  Edit a book's Record\n4.  Delete a Book\n5.  Return to the Main Menu\n\n";
        cout << "Enter your choice: ";
        
        //getting the user's choice with input validation
        do {
            cin >> choice;
            if (choice < 1 || choice > 5) {
                cout << "Invalid choice. (Please enter a number 1 - 5)\n";
                cout << "Enter your choice: ";
            }
        } while (choice < 1 || choice > 5);

        //switch statment to print the user's choice
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
                cout << "You selected item 5.";
                break;
        }
    }

}

//stub functions

//adds book to the inventory
void addBook() {
    //for loop to search the arrays for an empty slot
    for (int i = 0; i < SIZE; i++) {
        if (books[i].getTitle()[0] == 0) {
            cout << "Enter the book title: ";
            cin.ignore();
            cin.getline(input, 51);
            strUpper(input);
            books[i].setTitle(input);

            cout << "Enter the ISBN: ";
            cin.getline(input, 51);
            strUpper(input);
            books[i].setIsbn(input);

            cout << "Enter the author: ";
            cin.getline(input, 51);
            strUpper(input);
            books[i].setAuthor(input);

            cout << "Enter the publisher: ";
            cin.getline(input, 51);
            strUpper(input);
            books[i].setPub(input);

            cout << "Enter the date added: ";
            cin.getline(input, 51);
            strUpper(input);
            books[i].setDateAdded(input);

            cout << "Enter the quantity on hand: ";
            int newQty; 
            cin >> newQty;
            books[i].setQty(newQty);

            cout << "Enter the wholesale cost: ";
            double newWholesale; 
            cin >> newWholesale;
            books[i].setWholesale(newWholesale);

            cout << "Enter the retail price: ";
            double newRetail; 
            cin >> newRetail;
            books[i].setRetail(newRetail);

            cout << "Added book " << books[i].getTitle() << " to inventory.\n";
            return;
        }
    }    
}

//finds book in the inventory
void lookUpBook(){
    char searchBook[51];
    cout << "What book do you want to search for? ";
    cin.ignore();
    cin.getline(searchBook, 51);
    strUpper(searchBook);
    //for loop to search the arrays for the book
    for (int i = 0; i < SIZE; i++) {
        if (strstr(books[i].getTitle(), searchBook)) {
            cout << "Possible match found: " << books[i].getTitle() << endl;
            cout << "Is this correct? (y/n): ";
            char choice;
            cin >> choice;
            while(choice != 'y' && choice != 'n') {
                cout << "Invalid input. Please try again.\n";
                cout << "Is this correct? (y/n): ";
                cin >> choice;
            }
            if (choice == 'y'){
                bookInfo(books[i].getIsbn(), books[i].getTitle(), books[i].getAuthor(), books[i].getPub(), books[i].getDateAdded(), books[i].getQty(), books[i].getWholesale(), books[i].getRetail(), true);
                return;
            }
            if (i == SIZE - 1) {
                cout << "The book you searched for does not exist.\n";
            }
        }
    }
    cout << "Book not found.\n";
}

//edits book in the inventory
void editBook() {
    char editBook[51];
    int choice = 0;
    cout << "What book do you want to edit? ";
    cin.ignore();
    cin.getline(editBook, 51);
    //for loop to search the arrays for the book to edit
    for (int i = 0; i < SIZE; i++) {
        if (strstr(books[i].getTitle(), editBook)) {
            cout << "Possible match found: " << books[i].getTitle() << endl;
            cout << "Is this correct? (y/n): ";
            char cont;
            cin >> cont;
            while(cont != 'y' && cont != 'n') {
                cout << "Invalid input. Please try again.\n";
                cout << "Is this correct? (y/n): ";
                cin >> cont;
            }
            if(cont == 'y'){
                //printing the book info
                bookInfo(books[i].getIsbn(), books[i].getTitle(), books[i].getAuthor(), books[i].getPub(), books[i].getDateAdded(), books[i].getQty(), books[i].getWholesale(), books[i].getRetail(), true);
                cout << "Which field do you want to edit?\n";
                cout << "1.  Book Title\n2.  ISBN\n3.  Author\n4.  Publisher\n5.  Date Added\n6.  Quantity On Hand\n7.  Wholesale Cost\n8.  Retail Price\n9.  Cancel\n\nEnter your choice: ";
                cin >> choice;
                cin.ignore();
                //switch statement to edit the book info
                switch (choice) {
                    case 1:
                        cout << "Enter the new book title: ";
                        cin.getline(input, 51);
                        strUpper(input);
                        books[i].setTitle(input);

                        break;
                    case 2:
                        cout << "Enter the new ISBN: ";
                        cin.getline(input, 51);
                        strUpper(input);
                        books[i].setIsbn(input);
                        break;
                    case 3:
                        cout << "Enter the new author: ";
                        cin.getline(input, 51);
                        strUpper(input);
                        books[i].setAuthor(input);
                        break;
                    case 4:
                        cout << "Enter the new publisher: ";
                        cin.getline(input, 51);
                        strUpper(input);
                        books[i].setPub(input);
                        break;
                    case 5:
                        cout << "Enter the new date added: ";
                        cin.getline(input, 51);
                        strUpper(input);
                        books[i].setDateAdded(input);
                        break;
                    case 6:
                        cout << "Enter the new quantity on hand: ";
                        int newQty; 
                        cin >> newQty;
                        books[i].setQty(newQty);
                        break;
                    case 7:
                        cout << "Enter the new wholesale cost: ";
                        double newWholesale; 
                        cin >> newWholesale;
                        books[i].setWholesale(newWholesale);
                        break;
                    case 8:
                        cout << "Enter the new retail price: ";
                         double newRetail; 
                        cin >> newRetail;
                        books[i].setRetail(newRetail);
                        break;
                    case 9:
                        cout << "Canceled.\n";
                        return;
                    default:
                        cout << "Invalid choice.\n";
                        break;
                }
            } else if(cont == 'n') {
                
            }
            cout << "Book " << books[i].getTitle() << " has been edited.\n";
            return;
        }
    }
    cout << "Book not found.\n";
}

//deletes book from the inventory
void deleteBook() {
    char deleteBook[51];
    cout << "What book do you want to delete?\n";
    cin.ignore();
    cin.getline(deleteBook, 51);
    //for loop to search the arrays for the book to delete
    for (int i = 0; i < SIZE; i++) {
        if (strstr(books[i].getTitle(), deleteBook)) {
            cout << "Book " << books[i].getTitle() << " has been deleted.\n";
            books[i].removeBook();
            return;
        }
    }
    cout << "Book not found.\n";
}