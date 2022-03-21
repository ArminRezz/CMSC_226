/******************************************************************
** Program: Programming Project 2: Reports.cpp
** Description: Displays Reports Menu, recieves and validates user input, branches to other modules
** Course: CMSC226 CRN 36331
** Professor: Ping-Wei Tsai
** Student: Armin Rezaiyan-Nojani
** Due Date: 02/14/22
******************************************************************/

#include "reports.h"
const int ARRAY_SIZE = 20;
int indicies[ARRAY_SIZE]; // holds indexes of sorted array 

// Displays menu options for reports
void reports() {
    cout << "\n**************************************************\n" << endl;
    cout << "Serendipity Booksellers" << endl; 
    cout << "\tReports\n" << endl; 
    cout << "1. Inventory Listing" << endl; 
    cout << "2. Inventory Wholesale Value" << endl; 
    cout << "3. Inventory Retail Value" << endl; 
    cout << "4. Listing by Quantity" << endl; 
    cout << "5. Listing by Cost" << endl; 
    cout << "6. Listing by Age" << endl; 
    cout << "7. Return to Main Menu\n" << endl; 

    cout << "\n**************************************************\n" << endl;

    handleUserChoice();
}

// Gets user selection and reroutes to corresponding function
void handleUserChoice() {

    int choice = 0; 
    cout << "Enter your choice: ";
    cin >> choice;
    while (choice <= 0 || choice > 7) {
        cout << "Please enter number in range 1 - 7" << endl;
        cout << "Enter your choice: "; 
        cin >> choice; 
    }
    cout << "You chose option " << choice << endl; 

     switch(choice) {
        case 1: 
            repListing();
            break;
        case 2:
            repWholesale();
            break; 
        case 3:
            repRetail();
            break; 
        case 4:
            repQty();
            break; 
        case 5:
            repCost();
            break;
        case 6:
            repAge();
            break;
        case 7:
            break;
    }

}

void repListing() {
    
    cout << left << setw(20) << "Title" << setw(20) << "ISBN" << setw(20) << "Author"; 
    cout << left << setw(20) << "Publisher" << setw(20) << "Data Added" << setw(20) <<  "Quantity on hand";  
    cout << left << setw(20) << "Wholesale cost" << setw(20) << "Retail price" << endl; 
    for (int i = 0; i < ARRAY_SIZE; i++) {
       if (isbnArr[i] == "") {
           i = ARRAY_SIZE; 
       } else {
           cout << left << setw(20) << bookTitles[i] << setw(20) << isbnArr[i] << setw(20) << author[i]; 
           cout << setw(20) << publisher[i] << setw(20) << dateAdded[i] << setw(20) <<  quantityOnHand[i];  
           cout << setw(20) << wholesaleCost[i] << setw(20) << retailPrice[i] << endl; 
       }
    }
    return; 
}

void repWholesale() {
    cout << left << setw(20) << "Title" << setw(20) << "ISBN" << setw(20) << "Quantity" << setw(20) << "Wholesale Cost" << endl;  
    for (int i = 0; i < ARRAY_SIZE; i++) {
       if (isbnArr[i] == "") {
           i = ARRAY_SIZE; 
       } else {
           cout << left << setw(20) << bookTitles[i] << setw(20) << isbnArr[i] << setw(20) << quantityOnHand[i]  << setw(20) << wholesaleCost[i] << endl;  
       }
    }

    for (int i = 0; i < ARRAY_SIZE; i++) {
        int total = 0; 
        if (wholesaleCost != 0) {
            total += wholeSaleCost[i] * quantityOnHand[i]; 
        } else {
            i = ARRAYSIZE; 
        }
    }
    cout << "Total Wholesale: " << total << endl; 
    return; 
}

void repRetail() {
    cout << left << setw(20) << "Title" << setw(20) << "ISBN" << setw(20) << "Quantity" << setw(20) << "Retail Price" << endl;  
    for (int i = 0; i < ARRAY_SIZE; i++) {
       if (isbnArr[i] == "") {
           i = ARRAY_SIZE; 
       } else {
           cout << left << setw(20) << bookTitles[i] << setw(20) << isbnArr[i] << setw(20) << quantityOnHand[i]  << setw(20) << retailPrice[i] << endl;
       }
    }
    return; 
}

void repQty() {
    selectionSort(quantityOnHand);
    cout << left << setw(20) << "Title" << setw(20) << "ISBN" << setw(20) << "Quantity" << endl;  
    for (int i = 0; i < ARRAY_SIZE; i++) {
       if (quantityOnHand[i] != 0) {
            cout << left << setw(20) << bookTitles[indicies[i]] << setw(20) << isbnArr[indicies[i]] << setw(20) << quantityOnHand[indicies[i]] << endl;  
       } else {
           i = ARRAY_SIZE;
       }
    }
    return; 
}

void repCost() {
    selectionSort(wholesaleCost);
    cout << left << setw(20) << "Title" << setw(20) << "ISBN" << setw(20) << "Quantity" << setw(20) << "Wholesale cost" << endl;  
    for (int i = 0; i < ARRAY_SIZE; i++) {
       if (wholesaleCost[i] != 0) {
          cout << left << setw(20) << bookTitles[indicies[i]] << setw(20) << isbnArr[indicies[i]] << setw(20) << quantityOnHand[indicies[i]] << setw(20) << wholesaleCost[indicies[i]] << endl;  
        } else {
           i = ARRAY_SIZE; 
        }
    }
    return; 
}

void repAge() {
    cout << left << setw(20) << "Title" << setw(20) << "ISBN" << setw(20) << "Quantity" << setw(20) << "Date Added" << endl;  

    for (int i = ARRAY_SIZE; i > 0; i--) {
       if (isbnArr[i] != "") {
            cout << left << setw(20) << bookTitles[i] << setw(20) << isbnArr[i] << setw(20) << quantityOnHand[i] << setw(20) << dateAdded[i] << endl;  
       }
    }
    return; 
}

// returns array that holds indexes of sorted array
void selectionSort(double arr[]) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        indicies[i] = i;
    }
    for(int i = 0; i < ARRAY_SIZE; i++) {
        for(int j=i+1; j < ARRAY_SIZE; j++) {
            if(arr[i] < arr[j]){
                indicies[i] = j; 
                indicies[j] = i;
            }
        }
    }
}

// returns array that holds indexes of sorted array
void selectionSort(int arr[]) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        indicies[i] = i;
    }
    for(int i = 0; i < ARRAY_SIZE; i++) {
        for(int j=i+1; j < ARRAY_SIZE; j++) {
            if(arr[i] < arr[j]) {
                indicies[i] = j; 
                indicies[j] = i;
            }
        }
    }
}
