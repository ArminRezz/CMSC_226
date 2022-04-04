#include "bookdata.h"
#include "strupper.h"

const int SIZE = 20; 
extern BookData books[20];

void setTitle(char* title, int i) {
    strUpper(title);
    strcpy(books[i].title , title);
}
void setIsbn(char* isbn, int i) {
    strUpper(isbn);
    strcpy(books[i].isbn, isbn);
}
void setAuthor(char* author, int i) {
    strUpper(author);
    strcpy(books[i].author , author);
}
void setPub(char* publisher, int i) {
    strUpper(publisher);
    strcpy(books[i].publisher, publisher);
}
void setDateAdded(char* dateAdded, int i) {
    strUpper(dateAdded);
    strcpy(books[i].dateAdded, dateAdded);
}
void setQty(int qty, int i) {
    books[i].qtyOnHand = qty;  
}
void setWholesale(double price, int i) {
    books[i].wholesale = price;
}
void setRetail(double price, int i) {
    books[i].retail = price;
}
int isEmpty(int i) {
    return (books[i].title[0] == 0) ? 1 : 0;
}
void removeBook(int i) {
    books[i].title[0] = 0; 
    books[i].isbn[0] = 0;
}
