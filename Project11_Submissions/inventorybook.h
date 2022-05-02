// Specification file for the 'BookData' Class
#ifndef INVENTORYBOOK_H
#define INVENTORYBOOK_H

#include <fstream>
#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstring>
#include "bookdata.h"

using namespace std;


class InventoryBook : public BookData 
{
private:
	char	dateAdded[STR_SIZE];	 // stores the date a book was added into inventory
	int		qtyOnHand;				 // stores the quantity on hand of a book
	double	wholesale;				 // stores the wholesale price of a book
	double	retail;					 // stores the retail price of a book
public:
	InventoryBook();						 // the default constructor	
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