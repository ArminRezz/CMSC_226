#include "bookdata.h"
#include "strupper.h"

BookData::BookData(){
    title[0] = '\0';
    isbn[0] = '\0';
    author[0] = '\0';
    publisher[0] = '\0';
}

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