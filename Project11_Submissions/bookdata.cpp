#include "bookdata.h"
#include "strupper.h"

// title
void BookData::setTitle(char* title) {
    strUpper(title);
    strcpy(this->title , title);
}
char* BookData::getTitle() {
    return title;
}

// Isbn 
void BookData::setIsbn(char* isbn) {
    strUpper(isbn);
    strcpy(this->isbn, isbn);
}
char* BookData::getIsbn() {
    return isbn;
}

// author
void BookData::setAuthor(char* author) {
    strUpper(author);
    strcpy(this->author , author);
}
char* BookData::getAuthor() {
    return author;
}

//Publisher
void BookData::setPub(char* publisher) {
    strUpper(publisher);
    strcpy(this->publisher, publisher);
}
char* BookData::getPub() {
    return publisher;
}

// Date Added
void BookData::setDateAdded(char* dateAdded) {
    strUpper(dateAdded);
    strcpy(this->dateAdded, dateAdded);
}
char* BookData::getDateAdded() {
    return dateAdded;
}

// Quantity 
void BookData::setQty(int qty) {
    this->qtyOnHand = qty;  
}
int BookData::getQty() {
    return qtyOnHand;
}
int* BookData::getQtyAddress() {
    return &qtyOnHand;
}

// Wholesale
void BookData::setWholesale(double price) {
    this->wholesale = price;
}
double BookData::getWholesale() {
    return wholesale;
}
double* BookData::getWholesaleAddress() {
    return &wholesale;
}

// Retail
void BookData::setRetail(double price) {
    this->retail = price;
}
double BookData::getRetail() {
    return retail;
}

// check if book is empty
int BookData::isEmpty(int i) {
    return (this->title[0] == 0) ? 1 : 0;
}

// remove book
//void Bookdata::removeBook(BookData &book, fstream &file, int i) {
void BookData::removeBook() {
    this->title[0] = 0; 
    this->isbn[0] = 0;
}
