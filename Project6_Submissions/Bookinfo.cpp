/******************************************************************
** Program: Programming Project 4: Bookinfo.cpp
** Description: Displays information about particular book
** Course: CMSC226 CRN 36331
** Professor: Ping-Wei Tsai
** Student: Armin Rezaiyan-Nojani
** Due Date: 02/14/22
******************************************************************/

#include "bookinfo.h"

// displays information about any given book 
void bookInfo(char i[14], char t[51], char a[31], char p[31], char d[11], int q, double w, double r) {
    cout << "\n**************************************************\n" << endl;
    cout << "\tSerendipity Booksellers" << endl; 
    cout << "\tBook Information\n" << endl;  
    cout << "ISBN:" << i << endl; 
    cout << "Title:" << t << endl; 
    cout << "Author:" << a << endl; 
    cout << "Publisher:" << p << endl; 
    cout << "Date Added:" << d << endl; 
    cout << "Quantity-On-Hand:" << q << endl; 
    cout << "Wholesale Cost:" << w << endl; 
    cout << "Retail Price:" << r << endl; 
    cout << "\n**************************************************\n" << endl;
    return;
}
