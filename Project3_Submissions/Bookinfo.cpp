/******************************************************************
** Program: Programming Project 2: Bookinfo.cpp
** Description: Displays information about particular book
** Course: CMSC226 CRN 36331
** Professor: Ping-Wei Tsai
** Student: Armin Rezaiyan-Nojani
** Due Date: 02/14/22
******************************************************************/

#include <iostream>
#include "bookinfo.h"

using namespace std;

// displays information about any given book
void Bookinfo::bookInfo() {
    cout << "\n**************************************************\n" << endl;
    cout << "\tSerendipity Booksellers" << endl; 
    cout << "\tBook Information\n" << endl;  
    cout << "ISBN:" << endl; 
    cout << "Title:" << endl; 
    cout << "Author:" << endl; 
    cout << "Publisher:" << endl; 
    cout << "Date Added:" << endl; 
    cout << "Quantity-On-Hand:" << endl; 
    cout << "Wholesale Cost:" << endl; 
    cout << "Retail Price:" << endl; 
    cout << "\n**************************************************\n" << endl;
}
 