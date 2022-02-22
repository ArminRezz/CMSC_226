/******************************************************************
** Program: Programming Project 4: Bookinfo.cpp
** Description: Displays information about particular book
** Course: CMSC226 CRN 36331
** Professor: Ping-Wei Tsai
** Student: Armin Rezaiyan-Nojani
** Due Date: 02/14/22
******************************************************************/

#include <iostream>
#include "bookinfo.h"

using namespace std;

// displays information about any given book// displays information about any given book
void Bookinfo::bookInfo(string i, string t, string a, string p, string d, int q, double w, double r) {
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
}
 