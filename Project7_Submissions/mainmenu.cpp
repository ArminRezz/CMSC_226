// ********************************************************
// Starting Out with C++                                  *
// From Control Stuctures through Objects                 *
// seventh edition                                        *
//                                                        *
// Chapter 10 Characters, C-Strings, and More About       *
//            the String Class                            *
//                                                        *
// Serendipity Booksellers Software Development           *
// Project � Part 10: A Problem-Solving Exercise          *
//                                                        *
// Multi-File Program                                     *
// ********************************************************
#include <iostream>
#include <iomanip>
#include "mainmenu.h"
using namespace std;

const int	 NUM_WIDTH	 =  6;			// the numeric display length
const int	 TITLE_WIDTH = 26;			// the title display length
const int	 ISBN_WIDTH	 = 14;			// the ISBN display length
const int	 PRECISION	 =  2;			// the decimal precision

const int	 NUM_BOOKS	 = 20;			// represents the number of books in inventory
const int	 STR_SIZE	 = 51;			// represents the maximum string size

const double SALES_TAX	 =  0.06;		// the rate of the sales tax

char bookTitle	[NUM_BOOKS][STR_SIZE];	// stores the book title of each book
char isbn		[NUM_BOOKS][STR_SIZE];	// stores the isbn number of each book
char author		[NUM_BOOKS][STR_SIZE];	// stores the author's name of each book
char publisher	[NUM_BOOKS][STR_SIZE];	// stores the publisher's name of each book
char dateAdded	[NUM_BOOKS][STR_SIZE];	// stores the date each book was added

int	   qtyOnHand[NUM_BOOKS];			// stores the quantity on hand of each book
double wholesale[NUM_BOOKS];			// stores the wholesale price of each book
double retail	[NUM_BOOKS];			// stores the retail price of each book
char   date		[NUM_BOOKS];			// stores the date

int main()
{
	int choice = 0; // stores user's choice

	// display the 'Main Menu' until item 4 is selected
	while (choice != 4)
	{
		// display company name and screen title
		cout << "\n\nSerendipity Booksellers\n";
		cout << "Main Menu\n\n";

		// display menu items
		cout << "\n1.Cashier Module\n";
		cout << "2.Inventory Database Module\n";
		cout << "3.Report Module\n";
		cout << "4.Exit\n\n";

		// display user prompt
		cout << "Enter Your Choice: ";
		cin >> choice;

		// validate the user's input
		while (choice < 1 || choice > 4)
		{
			cout << "\nPlease enter a number in the range 1 - 4.\n\n";

			cout << "Enter Your Choice: ";
			cin >> choice;
		}

		// call the selected function
		switch (choice)
		{ 
			case 1:
				cashier();
					break;

			case 2:
				invMenu();
					break;

			case 3:
				reports();
					break;

			case 4:
				cout << "\nGoodbye\n\n\n";
				exit(0);
					break;

		}	// end switch

	}	// end the 'Main Menu' while loop

	cout << endl << endl;

	return 0;
}

