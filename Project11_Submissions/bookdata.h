// Specification file for the 'BookData' Class
#ifndef BOOKDATA_H
#define BOOKDATA_H

#include <fstream>
#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstring>
using namespace std;

const int STR_SIZE	= 51;			    // represents the maximum string size
const char FNAME[]  = "inventory.dat";	// represents the inventory file name

class BookData
{
private:
	char	title    [STR_SIZE];	 // stores the tile of a book
	char	isbn	 [STR_SIZE];	 // stores the isbn number of a book
	char	author	 [STR_SIZE];	 // stores the book author's name 
	char	publisher[STR_SIZE];	 // stores the book publisher's name 
	char	dateAdded[STR_SIZE];	 // stores the date a book was added into inventory
	int		qtyOnHand;				 // stores the quantity on hand of a book
	double	wholesale;				 // stores the wholesale price of a book
	double	retail;					 // stores the retail price of a book
public:
	BookData();						 // the default constructor	
	void   setTitle	   (char*);		 // sets the title of a book
	char*  getTitle    ();			 // returns the title of a book
	void   setIsbn	   (char*);		 // sets the ISBN of a book
	char*  getIsbn	   ();			 // returns the ISBN of a book
	void   setAuthor   (char*);		 // sets the author of a book
	char*  getAuthor   ();			 // returns the author of a book
	void   setPub      (char*);		 // sets the publisher of a book
	char*  getPub      ();			 // returns the publisher of a book
	void   setDateAdded(char*);		 // sets the date a book was added into inventory
	char*  getDateAdded();			 // returns the date a book was added into inventory
	void   setQty	   (int);		 // sets the quantity on hand of a book
	int    getQty      ();	         // returns the quantity on hand of a book
    int*    getQtyAddress();	  
	void   setWholesale(double);	 // sets the wholesale cost of a book
	double getWholesale();	         // returns the wholesale cost of a book
    double* getWholesaleAddress ();
	void   setRetail   (double);	 // sets the retail price of a book
	double getRetail   ();	         // returns the retail price of a book 
	int    isEmpty     (int /*BookData &*/); // returns an integer representing true or false

	// removes a book from inventory and writes the changes made into the inventory file
    // BookData &, fstream &, int
	void   removeBook  ();	
};
#endif