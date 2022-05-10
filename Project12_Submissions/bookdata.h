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

};
#endif