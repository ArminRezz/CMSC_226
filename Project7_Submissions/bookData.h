#ifndef BOOKDATA_H
#define BOOKDATA_H

#include <iostream>
#include <string>
#include <cstring> 
#include <cctype>

using namespace std;

const int STRING_SIZE = 51;

struct BookData {
    char title[STRING_SIZE];
    char isbn[STRING_SIZE];
    char author[STRING_SIZE];
    char publisher[STRING_SIZE];
    char dateAdded[STRING_SIZE];
    int qtyOnHand;
    double wholesale;
    double retail;
};

void setTitle(char*, int);
void setIsbn(char*, int);
void setAuthor(char*, int);
void setPub(char*, int);
void setDateAdded(char*, int);
void setQty(int, int);
void setWholesale(double, int);
void setRetail(double, int);
int isEmpty(int);
void removeBook(int);

#endif