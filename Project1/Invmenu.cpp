#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "invmenu.h"

using namespace std;

// Displays menu options for inventory
void Invmenu::displayInventoryMenu() { 
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
            //findBook();
            break;
        case 2:
            //addBook();
            break; 
        case 3:
            //editBookRecord();
            break; 
        case 4:
            //deleteBook();
            break; 
        case 5:
            break;
    }

}

void Invmenu::lookUpBook() {
    // Create a text string, which is used to output the text file
    string myText;
    // Read from the text file
    ifstream MyReadFile("filename.txt");

    // Use a while loop together with the getline() function to read the file line by line
    while (getline (MyReadFile, myText)) {
        // Output the text from the file
        cout << myText;
    }

    // Close the file
    MyReadFile.close();

    return;
}
void Invmenu::addBook() {
    // Create and open a text file
    ofstream MyFile("filename.txt");
    // Write to the file
    MyFile << "Files can be tricky, but it is fun enough!";
    // Close the file
    MyFile.close();
    return;
}
void Invmenu::editBook() {
    return;
}
void Invmenu::deleteBook() {
    return;
}
