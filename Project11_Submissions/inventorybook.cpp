#include "inventorybook.h"
#include "strupper.h"

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
