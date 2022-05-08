#include "inventorybook.h"
#include "strupper.h"

InventoryBook::InventoryBook(){
    dateAdded[0] = '\0';
    qtyOnHand = 0;
    wholesale = 0.0;
    retail = 0.0;
}

// Date Added
void InventoryBook::setDateAdded(char* dateAdded) {
    strUpper(dateAdded);
    strcpy(this->dateAdded, dateAdded);
}
char* InventoryBook::getDateAdded() {
    return dateAdded;
}

// Quantity 
void InventoryBook::setQty(int qty) {
    this->qtyOnHand = qty;  
}
int InventoryBook::getQty() {
    return qtyOnHand;
}
int* InventoryBook::getQtyAddress() {
    return &qtyOnHand;
}

// Wholesale
void InventoryBook::setWholesale(double price) {
    this->wholesale = price;
}
double InventoryBook::getWholesale() {
    return wholesale;
}
double* InventoryBook::getWholesaleAddress() {
    return &wholesale;
}

// Retail
void InventoryBook::setRetail(double price) {
    this->retail = price;
}
double InventoryBook::getRetail() {
    return retail;
}

// check if book is empty
int InventoryBook::isEmpty(int i) {
    return (this->getTitle()[0] == 0) ? 1 : 0;
}

// remove book
//void Bookdata::removeBook(BookData &book, fstream &file, int i) {
void InventoryBook::removeBook() {
    this->getTitle()[0]  = 0; 
    this->getTitle()[0]  = 0;
}

