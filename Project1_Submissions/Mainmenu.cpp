#include <iostream>

using namespace std; 

int main() {

    cout << "\n**************************************************\n" << endl;
    cout << "Serendipity Booksellers" << endl; 
    cout << "\tMain Menu\n" << endl; 
    cout << "1. Cashier Module" << endl; 
    cout << "2. Inventory Database Module" << endl; 
    cout << "3. Report Module" << endl; 
    cout << "4. Exit" << endl; 

    int choice = 0;
    do {
        cout << "Enter your choice: "; 
        cin >> choice; 
    } while (choice <= 0 || choice > 4); 

    return 0; 
}