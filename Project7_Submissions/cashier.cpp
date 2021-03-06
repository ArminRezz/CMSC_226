#include "cashier.h"
#include "bookdata.h"
#include "invmenu.h"

const int SIZE = 20; 
extern BookData books[20];

//declaration of cashier function
void cashier(){
    //declaring variables
    char date[SIZE][11], isbn[SIZE][14], title[SIZE][51];
    float price[10], total[10], Total = 0, tax = 0;
    int quantity[10];
    string choice = "";

    //big loop to allow multiple transactions
    do {
        
        //index to keep track of titles
        int index = 0; 

        cout << "Serendipity Booksellers\n" << "  Cashier Module\n\n";
        cout << "Enter the date: ";
        cin.ignore();
        cin.getline(date[index], 11);
        
        //smaller loop to allow multiple titles to be added
        while (true) {
            string cont = "";
            string a = "y";
            do {
                //prompting user for input
                cout << "Enter the ISBN: ";
                cin.getline(isbn[index], 14);

                //searching for isbn inside global isbn array
                for (int i = 0; i < SIZE; i++) {
                    if (strcmp(isbn[index], books[i].isbn)) {
                        strcpy(title[index], books[i].title);
                        price[index] = books[i].retail;
                        cout << "found book: " << title[index] << endl; 
                        //checking quantity
                        cout << "Enter the quantity: ";
                        cin >> quantity[index];
                        while (quantity[index] > books[i].qtyOnHand) {
                            cout << "Not enough quantity on hand. Please enter new quantity: \n";
                            cin >> quantity[index];
                        }
                        cout << "Added book" << endl;
                        total[index] = (price[index] * quantity[index]);
                        a = "n";
                        break;
                    }
                    if (index == SIZE-1) {
                        cout << "Book not found, try again? (y/n): ";
                        cin >> a;
                        //clearing cin
                        while (getchar() != '\n');

                        if (a == "n") {
                            break;
                        }
                    }
                }

            } while (a == "y");

            //input validation for the continue prompt
            while (cont != "y" && cont != "n") {
                cout << "Do you want to add another title? (y/n): ";
                cin >> cont;
                if (cont != "n" && cont != "y") {
                    cout << "Invalid input. Please try again.\n";
                }
            }

            //clearing cin
            while ((getchar()) != '\n');
            
            if (cont == "n") {
                break;
            } else {
                index++;
                cout << index << endl << endl;
            }

        }

        //printing the receipt
        cout << "\nSeredipity Book Sellers\n\n";
        cout << "Date: " << date[0] << "\n\n";

        //calculating total
        for (int i = 0; i < index+1; i++) {
            Total += total[i];
        }
        tax = Total * 0.06;
        Total = Total + tax;

        //list of items
        cout << left << setw(5) << "QTY" << setw(15) << "ISBN" << setw(25) << "Title" << setw(10) << "Price" << setw(10) << "Total" << endl;
        cout << "_________________________________________________________________\n";
        //loop to print the different titles
        for (int i = 0; i < index+1; i++) {
            cout << left << setw(5) << quantity[i] << setw(15) << isbn[i] << setw(25) << title[i] << setw(10) << price[i] << setw(10) << total[i] << endl;
        }
        cout << "          " << setw(45) << "Subtotal" << setw(2) << "$" << setw(8) << Total/1.06 << endl;
        cout << "          " << setw(45) << "Tax" << setw(2) << "$" << setw(8) << tax << endl;
        cout << "          " << setw(45) << "Total" << setw(2) << "$" << setw(8) << Total << endl << endl;
        cout << left << "Thank You for Shopping at Seredipity!\n\n";

        //prompting user for choice
        cout << "Would you like to process another transaction? (y/n): ";
        getline(cin, choice);
        
        while (choice != "y" && choice != "n"){
            cout << "Please enter a valid choice. (y/n): ";
            getline(cin, choice);
        }
        
    } while (choice == "y");

}