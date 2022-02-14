#include <iostream>
using namespace std; 

int main() {
    
    int choice = 0;
    do {
        // Display Inventory Database Menu
        cout << "Serendipity Booksellers" << endl; 
        cout << "Inventory Database\n" << endl; 
        cout << "1. Look Up a Book" << endl; 
        cout << "2. Add a Book" << endl; 
        cout << "3. Edit a Book’s Record" << endl; 
        cout << "4. Delete a Book" << endl; 
        cout << "5. Return to the Main Menu" << endl; 

        // Get VALID user input
        cout << "Enter your choice: ";
        cin >> choice;
        while (choice <= 0 || choice > 5) {
            cout << "Please enter number in range 1 - 5" << endl;
            cout << "Enter your choice: "; 
            cin >> choice; 
        }

    } while (choice != 5);

    return 0; 
}