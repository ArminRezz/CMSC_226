#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "invmenu.h"

using namespace std;

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
    getUserChoice();
}

void Invmenu::getUserChoice() {

    cout << "Enter your choice: " << endl;
    int choice = 0;
    cin >> choice; 

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
        default:
            break;
    }

}

void Invmenu::findBook() {
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
void Invmenu::editBookRecord() {
    return;
}
void Invmenu::deleteBook() {
    return;
}
void Invmenu::returnToMain() {
    return;
}