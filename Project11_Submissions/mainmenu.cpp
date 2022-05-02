#include <fstream>
#include <iostream>

//including the other functions
#include "cashier.h"
#include "bookdata.h"
#include "inventorybook.h"
#include "bookinfo.h"
#include "reports.h"
#include "invmenu.h"
#include "mainmenu.h"

using namespace std;

const int SIZE = 20; 
BookData books[20];
fstream invFile;

int main(){
    printMenu();
}

void printMenu(){

    //opens the inventory file
    invFile.open("inventory.dat", ios::in);
    //creates the inventory file if it does not exist
    if (invFile.fail()) {
        invFile.open("inventory.dat", ios::in);
        invFile.close();
        invFile.clear();
        cout << "New file has been created, you must add books to the inventory!";
    }
    //copies the data in the inventory file to the book struct
    else {
        for (int i = 0; i < 20; i++) {
            //loops until all 20 books are copied or the end of the file is reached
            if (invFile.eof())
                break;

            invFile.seekg(i * sizeof(books), ios::beg);
            invFile.read(reinterpret_cast<char*>(&books), sizeof(books));
        }
        //closes file
        invFile.close();
        invFile.clear();
    }
    
    //declaring choice variable
    int choice = 0;
    while(choice != 4) {

        //printing the menu
        cout << endl;
        cout << right << setw(20) << "\nSerendipity Booksellers\n" << setw(17) << "Main menu\n\n"; 
        cout << left << "1. Cashier Module" << endl;
        cout << "2. Inventory Database Module" << endl;
        cout << "3. Reports Module" << endl;
        cout << "4. Exit\n\n";
        cout << "Enter your choice: ";

        //getting the user's choice with input validation
        do {
            cin >> choice;
            if (choice < 1 || choice > 4) {
                cout << "Invalid choice. (Please enter a number 1 - 4)\n";
                cout << "Enter your choice: ";
            }
        } while (choice < 1 || choice > 4);

        //switch statment to print the user's choice
        switch (choice) {
            case 1: 
                cashier();
                break;
            case 2:
                invMenu();
                break;
            case 3:
                report();
                break;
            case 4:
                //opens the inventory file to input any new or changed data from the book struct
                invFile.open("inventory.dat", ios::out);
                //copies the data for all the 20 books into inventory file
                for (int i = 0; i < 20; i++) {
                    invFile.seekp(i * sizeof(books), ios::beg);
                    invFile.write(reinterpret_cast<char*>(&books), sizeof(books));
                }
                //closes file
                invFile.close();
                invFile.clear();
                break;
        }
    }

}