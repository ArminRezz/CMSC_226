#include "cashier.h"
#include "invmenu.h"
#include "inventorybook.h"
#include "soldbook.h"

const int SIZE = 20; 
extern InventoryBook books[20];

//declaration of cashier function
void cashier() {
    //declaring variables
    char date[SIZE][11], isbn[SIZE][14], title[SIZE][51];

    // replace with soldbook
    float price[10], total[10], Total = 0, tax = 0;
    int quantity[10], quant;
    string choice = "";

    //big loop to allow multiple transactions
    do {
        
        //index to keep track of titles
        int index = 0; 

        cout << "Serendipity Booksellers\n" << "  Cashier Module\n\n";
        cout << "Enter the date: ";
        cin.ignore();
        cin.getline(date[index], 11);
        
        //Asking how many books are being sold
        cout << "How many books are you buying today? ";
        cin >> quant;
        cin.ignore();

        //creating dynamically allocated array of sold books
        SoldBook *soldBooks;
        try {
             soldBooks = new SoldBook[quant];
        } catch (exception e){
            cout << "Error, bad memory allocation, aborting...";
            return;
        }

        //looping through to add books to the sold book array
        for (int i = 0; i < quant; i++) {
            string a = "y";
            do {
                cout << "Enter the ISBN: ";
                cin.getline(isbn[index], 14);
                //searching for isbn inside global isbn array
                for (int i = 0; i < SIZE; i++) {
                    if (strcmp(isbn[index], books[i].getIsbn()) == 0) {
                        strcpy(title[index], books[i].getTitle());
                        price[index] = books[i].getRetail();
                        cout << "found book: " << title[index] << endl; 
                        //checking quantity
                        cout << "Enter the quantity: ";
                        cin >> quantity[index];
                        while (quantity[index] > books[i].getQty()) {
                            cout << "Not enough quantity on hand. Please enter new quantity: \n";
                            cin >> quantity[index];
                        }
                        books[i].setQty(books[i].getQty() - quantity[index]);
                        cout << "Added book" << endl;
                        while(getchar() != '\n');
                        total[index] = (price[index] * quantity[index]);
                        a = "n";
                        break;
                    }
                    if (i == SIZE-1) {
                        cout << "Book not found, try again? (y/n): ";
                        cin >> a;
                        //clearing cin
                        while (getchar() != '\n');
                        if (a == "n") {
                            break;
                        }
                    }
                    soldBooks[i].setIsbn(isbn[index]);
                    soldBooks[i].setTitle(title[index]);
                    soldBooks[i].setRetail(books[i].getRetail());
                    soldBooks[i].setWholesale(books[i].getWholesale());
                    soldBooks[i].setQtySold(books[i].getQty());
                    soldBooks[i].setQtySold(quantity[index]);
                }
            } while (a == "y");
        }

        //printing the receipt
        cout << "\nSeredipity Book Sellers\n\n";
        cout << "Date: " << date[0] << "\n\n";

        //calculating total
        for (int i = 0; i < quant; i++) {
            soldBooks[i].addTotal(total[i] + soldBooks[i].getTax());
        }

        //list of items
        cout << left << setw(5) << "QTY" << setw(15) << "ISBN" << setw(25) << "Title" << setw(10) << "Price" << setw(10) << "Total" << endl;
        cout << "_________________________________________________________________\n";
        //loop to print the different titles
        for (int i = 0; i < quant; i++) {
            cout << left << setw(5) << soldBooks[i].getQtySold() << setw(15) << soldBooks[i].getIsbn() << setw(25) << soldBooks[i].getTitle() << setw(10) << soldBooks[i].getRetail() << setw(10) << soldBooks[i].setSubtotal() << endl;
        }
        cout << "          " << setw(45) << "Subtotal" << setw(2) << "$" << setw(8) << soldBooks[1].setSubtotal()/1.06 << endl;
        cout << "          " << setw(45) << "Tax" << setw(2) << "$" << setw(8) << soldBooks[1].getTax() << endl;
        cout << "          " << setw(45) << "Total" << setw(2) << "$" << setw(8) << soldBooks[1].getTotal() << endl << endl;
        cout << left << "Thank You for Shopping at Seredipity!\n\n";

        //prompting user for choice
        cout << "Would you like to process another transa~ction? (y/n): ";
        getline(cin, choice);
        
        while (choice != "y" && choice != "n"){
            cout << "Please enter a valid choice. (y/n): ";
            getline(cin, choice);
        }
        
    } while (choice == "y");

}