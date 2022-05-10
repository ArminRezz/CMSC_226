#include "reports.h"
#include "invmenu.h"
#include "inventorybook.h"
#include "bookinfo.h"
#include "mainmenu.h"

const int SIZE = 20; 
extern InventoryBook books[20];

void report(){
    
    //declaring choice variable
    int choice = 0;

    while (choice != 7) {
    
        //printing the report
        cout << right << setw(20) << "\nSerendipity Booksellers\n" << setw(16) << "Reports\n\n";
        cout << "1.  Inventory Listing\n";
        cout << "2.  Inventory Wholesale Value\n";
        cout << "3.  Inventory Retail Value\n";
        cout << "4.  Listing by Quantity\n";
        cout << "5.  Listing by Cost\n";
        cout << "6.  Listing by Age\n";
        cout << "7.  Return to Main Menu\n\n";
        cout << "Enter Your Choice: ";

        cin >> choice;
    
        //getting the user's choice with input validation
        while (choice < 1 || choice > 7){
            if (choice < 1 || choice > 7) {
                cout << "Invalid choice. (Please enter a number 1 - 7)\n";
                cout << "Enter your choice: ";
            }
        } 

        //switch statment to print the user's choice
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
                printMenu();
                return;
        }
    }
}

//stub functions
void repListing() {
    cout << "You selected a listing report.\n";
    
    for (int i = 0; i < SIZE; i++) {
        bookInfo(books[i].getIsbn(), books[i].getTitle(), books[i].getAuthor(), books[i].getPub(), books[i].getDateAdded(), books[i].getQty(), books[i].getWholesale(), books[i].getRetail(), false);
    }
    string c = "";
    cout << "Enter c to continue: ";
    cin >> c;
    if (c == "c") {
        report();
    }
}

void repWholesale() {
    cout << "You selected a wholesale report.\n";
    double total = 0;
    for (int i = 0; i < SIZE; i ++) {
        cout << "Title: " << books[i].getTitle() << endl;
        cout << "ISBN: " << books[i].getIsbn() << endl;
        cout << "Quantity On hand: " << books[i].getQty() << endl;
        cout << "Wholesale Cost: " << books[i].getWholesale() << endl;
        total += books[i].getWholesale() * books[i].getQty();
        cout << "\n\n";
    }
    cout << "Total Wholesale Value: " << total << endl;
    string c = "";
    cout << "Enter c to continue: ";
    cin >> c;
    if (c == "c") {
        report();
    }
}

void repRetail() {
    cout << "You selected retail report.\n";
    double total = 0;
    for (int i = 0; i < SIZE; i ++){
        if (books[i].getTitle()[0] != 0) {
            cout << "Title: " << books[i].getTitle() << endl;
            cout << "ISBN: " << books[i].getIsbn() << endl;
            cout << "Quantity On hand: " << books[i].getQty() << endl;
            cout << "Retail Price: " << books[i].getRetail() << endl;
            total += books[i].getRetail() * books[i].getQty();
            cout << "\n\n";
        }
    }
    cout << "Total Retail Value: " << total << endl;
    string c = "";
    cout << "Enter c to continue: ";
    cin >> c;
    if (c == "c") {
        report();
    }
}

//sorts the array in decending order by quantity
void repQty() {
    cout << "You selected a sorted quantity report.\n";
    int *qtyPtr[SIZE];
    int idPtr[SIZE];

    for (int i = 0; i < SIZE; i ++) {
        qtyPtr[i] = books[i].getQtyAddress();
    }
    
    //selection sorting the array
    int i, j, max_idx; 

    for (i = 0; i < SIZE-1; i++) 
    { 
        max_idx = i; 
        for (j = i+1; j < SIZE; j++) 
        if (*qtyPtr[j] > *qtyPtr[max_idx]) 
            max_idx = j; 

        //swapping the values
        int *temp = qtyPtr[max_idx];
        qtyPtr[max_idx] = qtyPtr[i];
        qtyPtr[i] = temp;
    } 

    //printing the sorted array
    for (int i = 0; i < SIZE; i ++) {
        idPtr[i] = *qtyPtr[i];
        if (books[idPtr[i]].getTitle()[0] != 0) {
            cout << "Title: " << books[idPtr[i]].getTitle() << endl;
            cout << "ISBN: " << books[idPtr[i]].getIsbn() << endl;
            cout << "Quantity On hand: " << books[idPtr[i]].getQty() << endl;
            cout << "\n\n";
        }
    }
    string c = "";
    cout << "Enter c to continue: ";
    cin >> c;
    if (c == "c") {
        report();
    }
}

//sorts the array in decending order by cost
void repCost() {
    cout << "You selected sorted cost report.\n";
    double *costPtr[SIZE];
    int idPtr[SIZE];
    for (int i = 0; i < SIZE; i ++) {
        costPtr[i] = books[i].getWholesaleAddress();
    }

    //selection sorting the array
    int i, j, max_idx;
    
    for (i = 0; i < SIZE-1; i++) 
    { 
        max_idx = i; 
        for (j = i+1; j < SIZE; j++) 
        if (*costPtr[j] > *costPtr[max_idx]) 
            max_idx = j; 

        //swapping the values
        double *temp = costPtr[max_idx];
        costPtr[max_idx] = costPtr[i];
        costPtr[i] = temp;
    }

    //printing the sorted array
    for (int i = 0; i < SIZE; i ++) {
        idPtr[i] = costPtr[i]-books[0].getWholesaleAddress();
        if (books[idPtr[i]].getTitle()[0] != 0) {
            cout << "Title: " << books[idPtr[i]].getTitle() << endl;
            cout << "ISBN: " << books[idPtr[i]].getIsbn() << endl;
            cout << "Wholesale Cost: " << books[idPtr[i]].getWholesale() << endl;
            cout << "\n\n";
        }
    }
    string c = "";
    cout << "Enter c to continue: ";
    cin >> c;
    if (c == "c") {
        report();
    }

}

//sorts the array in decending order by age
void repAge() {
    cout << "You selected a sorted age report.\n";
    char *agePtr[SIZE];
    int idPtr[SIZE];
    for (int i = 0; i < SIZE-1; i ++) {   //make an array of pointers to the dateAdded array
        agePtr[i] = books[i].getDateAdded();
        idPtr[i] = i;
    }

    //selection sorting the array
    int i, j, max_idx;

    for (i = 0; i < SIZE-1; i++) 
    { 
        max_idx = i; 
        for (j = i+1; j < SIZE-1; j++) {

            if (strcmp(agePtr[j], agePtr[max_idx]) >= 0){
                max_idx = j; 
            }
        }

        //swapping the values of max and i
        char *temp = agePtr[max_idx];
        agePtr[max_idx] = agePtr[i];
        agePtr[i] = temp;
        int tem = idPtr[max_idx];
        idPtr[max_idx] = idPtr[i];
        idPtr[i] = tem;  
    }

    //printing the sorted array
    for (int i = 0; i < SIZE-1; i ++) {
        if (books[idPtr[i]].getTitle()[0] != 0) {
            cout << "Title: " << books[idPtr[i]].getTitle() << endl;
            cout << "ISBN: " << books[idPtr[i]].getIsbn() << endl;
            cout << "Date Added: " << books[idPtr[i]].getDateAdded() << endl;
            cout << "\n\n";
        }
    }
    string c = "";
    cout << "Enter c to continue: ";
    cin >> c;
    if (c == "c") {
        report();
    }
}