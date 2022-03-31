// ********************************************************
// Starting Out with C++                                  *
// From Control Stuctures through Objects                 *
// seventh edition                                        *
//                                                        *
// Chapter 10 Characters, C-Strings, and More About       *
//            the String Class                            *
//                                                        *
// Serendipity Booksellers Software Development           *
// Project — Part 10: A Problem-Solving Exercise          *
//                                                        *
// Multi-File Program                                     *
// ********************************************************
#include <iostream>
#include "invmenu.h"
#include "strupper.h"
using namespace std;

const int	 STR_SIZE	 = 51;	// the maximum string size
const int	 NUM_BOOKS	 = 20;	// the number of books in inventory

// The following are external declarations for the various
// arrays used by the program.
extern char bookTitle [NUM_BOOKS][STR_SIZE];	// stores the book title of each book
extern char isbn      [NUM_BOOKS][STR_SIZE];	// stores the isbn number of each book
extern char author    [NUM_BOOKS][STR_SIZE];	// stores the author's name of each book
extern char publisher [NUM_BOOKS][STR_SIZE];	// stores the publisher's name of each book
extern char dateAdded [NUM_BOOKS][STR_SIZE];	// stores the date each book was added

extern int	  qtyOnHand[NUM_BOOKS];			// stores the quantity on hand of each book
extern double wholesale[NUM_BOOKS];			// stores the wholesale price of each book
extern double    retail[NUM_BOOKS];			// stores the retail price of each book

//********************************************
// lookUpbook function                       *
//********************************************

void lookUpBook()
{
	char title[STR_SIZE];	// stores a book title the user enters
	int  choice = 0;		// stores the user's numeric choice
	int row;                // Used in loops to step through the arrays.

	// prompt the user to enter a full or partial book title
	cin.ignore();
	cout << "\nPlease enter all or part of the title:  ";
	cin.getline(title, STR_SIZE);

	strUpper(title);		// Convert to uppercase
	
	// enter the 'book title search' for loop
	for (row = 0; row < NUM_BOOKS; row++)
	{
		// search for a match 
		if (strstr(bookTitle[row], title)) // if they match
		{  
			// display a possible match
			cout << "\nPossible Match Found:  " 
				 << bookTitle[row] 
			     << "\n\n";

			// prompt the user for confirmation
			cout << "Is this a Correct Match?\n";
			cout << "1.Yes\n";
			cout << "2.No\n\n";

			cout << "Enter Your Choice: ";
			cin >> choice;
			
			// validate the user's input
			while (choice != 1 && choice != 2)
			{
				cout << "Please enter a number in the range 1 - 2\n\n";

				cout << "Is this a Correct Match?\n";
				cout << "1.Yes\n";
				cout << "2.No\n\n";

				cout << "Enter Your Choice: ";
				cin >> choice;
			}

			if (choice == 1)
			{  
				// call function 'bookInfo' to display the results
				bookInfo(isbn[row], bookTitle[row], author[row], publisher[row],
						 dateAdded[row], qtyOnHand[row], wholesale[row], retail[row]);
				break;
			}
			else 
			{
				continue;
			}

		}	// end if

	}	// end the 'book title search' for loop

	if (row == NUM_BOOKS - 1)
	{
		cout << "\nSorry.  No title matching \'" 
			 << title 
			 << "\' was found."  
			 << "\n\n";
	}

}	// end function lookUpBook

//********************************************
// addBook function                          *
//********************************************

void addBook()
{
	// enter the 'first empty row' for loop
	for (int row = 0; row < NUM_BOOKS; row++)
	{
		// find the first book whose element is 0.
		if (bookTitle[row][0] == 0)
		{
			// prompt the user for book information
			cin.ignore();
			cout << "\nEnter Title: ";

			cin.getline(bookTitle[row],STR_SIZE);
			
			strUpper(bookTitle[row]);	// convert to uppercase

			cout << "\nEnter ISBN(#-###-#####-#): ";

			cin.getline(isbn[row],STR_SIZE);

			strUpper(isbn[row]);		// convert to uppercase
			
			cout << "\nEnter Author: ";

			cin.getline(author[row],STR_SIZE);

			strUpper(author[row]);		// convert to uppercase

			cout << "\nEnter Publisher: ";

			cin.getline(publisher[row],STR_SIZE);

			strUpper(publisher[row]);	// convert to uppercase
			
			cout << "\nEnter Date Added to Inventory (MM/DD/YYYY): ";

			cin.getline(dateAdded[row], STR_SIZE);

			cout << "\nEnter Quantity Being Added: ";
			cin >> (qtyOnHand[row]);

			cout << "\nEnter Wholesale Cost: ";
			cin >> (wholesale[row]);

			cout << "\nEnter Retail Price: ";
			cin >> (retail[row]);

			cout << "\n\nRecord was successfully entered.\n";
				break;
		}

		else if (row == NUM_BOOKS - 1)
		{
			cout << "\n\t\t****Sorry. Database is full.****\n\n";	
		}

	}	// end the 'first empty row' for loop

}	// end function addBook

//********************************************
// editBook function                         *
//********************************************

void editBook()
{
	char title[STR_SIZE];	// stores a book tile the user enters
	int  choice = 0;		// stores the user's numeric choice
	int row;                // Used in loops to step through the arrays.

	// prompt the user to enter a full or partial book title
	cin.ignore();
	cout << "\nPlease enter all or part of the title:  ";
	cin.getline(title, STR_SIZE);

	strUpper(title);		// Convert to uppercase
	
	// enter the 'book title search' for loop
	for (row = 0; row < NUM_BOOKS; row++)
	{
		// search for a match
		if (strstr(bookTitle[row], title)) // if they match
		{  
			// display a possible match
			cout << "\nPossible Match Found:  " 
				 << bookTitle[row] 
			     << "\n\n";

			// prompt the user for confirmation
			cout << "Is this a Correct Match?\n";
			cout << "1.Yes\n";
			cout << "2.No\n\n";

			cout << "Enter Your Choice: ";
			cin >> choice;
			
			// validate the user's input
			while (choice != 1 && choice != 2)
			{
				cout << "Please enter a number in the range 1 - 2\n\n";

				cout << "Is this a Correct Match?\n";
				cout << "1.Yes\n";
				cout << "2.No\n\n";

				cout << "Enter Your Choice: ";
				cin >> choice;
			}

			if (choice == 1)
			{  
				// call function 'bookInfo' to display the results
				bookInfo(isbn[row], bookTitle[row], author[row], publisher[row],
						 dateAdded[row], qtyOnHand[row], wholesale[row], retail[row]);
			do 
			{
				cout << "\nYou may edit any of the following fields:\n";
				cout << "\t1.  ISBN\n"; 
				cout << "\t2.  Title\n";
				cout << "\t3.  Author's Name\n";
				cout << "\t4.  Publisher's Name\n"; 
				cout << "\t5.  Date Book Was Added To Inventory\n";
				cout << "\t6.  Quantity On Hand\n";
				cout << "\t7.  Wholesale Cost\n"; 
				cout << "\t8.  Retail Price\n"; 
				cout << "\t9.  Exit\n\n";
				cout << "Please choose 1 - 8 to EDIT an item, or 9 to EXIT:  ";
				cin >> choice;

				// validate the user's input
				while (choice < 1 || choice > 9)
				{
					cout << "\nPlease choose 1 - 8 to EDIT an item, or 9 to CANCEL:  ";
					cin >> choice;
				}

				// diplay the selected item
				switch (choice)
				{

				case 1:
					cout << "\nCurrent ISBN:  " 
						 << isbn[row] 
						 << endl;

						cin.ignore();

					cout << "Enter new ISBN(#-###-#####-#): ";
					cin >>  isbn[row];

					strUpper(isbn[row]);	// convert to uppercase

						break;

				case 2:
					cout << "\nCurrent Title:  " 
						 << bookTitle[row] 
						 << endl;

						cin.ignore();

					cout << "Enter new Title:  ";
					cin.getline(bookTitle[row], STR_SIZE);

					strUpper(bookTitle[row]);	// convert to uppercase

						break;

				case 3:
					cout << "\nCurrent Author:  " 
						 << author[row] 
						 << endl;

						cin.ignore();

					cout << "Enter new Author:  ";
					cin.getline(author[row], STR_SIZE);

					strUpper(author[row]);	// convert to uppercase

						break;

				case 4:
					cout << "\nCurrent Publisher:  " 
						 << publisher[row] 
						 << endl;

						cin.ignore();

					cout << "Enter new Publisher:  ";
					cin.getline(publisher[row], STR_SIZE);

					strUpper(publisher[row]);	// convert to uppercase

						break;

				case 5:
					cout << "\nCurrent Date Entered Into Inventory:  " 
						 << dateAdded[row] 
						 << endl;

						cin.ignore();

					cout << "Enter new Date:  ";
					cin.getline(dateAdded[row], STR_SIZE);
						break;

				case 6:
					cout << "\nCurrent Quantity on Hand:  " 
						 << qtyOnHand[row] 
					     << endl;

						cin.ignore();

					cout << "Enter new Quantity on Hand:  ";
					cin >> qtyOnHand[row];

						break;

				case 7:
					cout << "\nCurrent Wholesale Cost:  " 
						 << wholesale[row] 
					     << endl;

						cin.ignore();

					cout << "Enter new Wholesale Cost:  ";
					cin >> wholesale[row];
						break;

				case 8:
					cout << "\nCurrent Retail Price:  " 
						 << retail[row] 
					     << endl;

						cin.ignore();

					cout << "Enter new Retail Price:  ";
					cin >> retail[row];

				} // end switch


			} while (choice != 9); // end do

				break;

		} // end if

			else 
			{
				continue;
			}

		}	// end 'Search for Match' if

	}	// end the 'book title search' for loop

	if (row == NUM_BOOKS - 1)
	{
		cout << "\nSorry.  No title matching \'" 
			 << title 
			 << "\' was found."  
			 << "\n\n";
	}

}	// end function editBook

//********************************************
// deleteBook function                       *
//********************************************

void deleteBook()
{
	char title[STR_SIZE];	// stores a book tile the user enters
	int  choice = 0;		// stores the user's numeric choice
	char response = 'N';	// stores the user's alphanumeric response
	int row;                // Used in loops to step through the arrays.

	// prompt the user to enter a full or partial book title
	cin.ignore();
	cout << "\nPlease enter all or part of the title:  ";
	cin.getline(title, STR_SIZE);

	strUpper(title);		// Convert to uppercase
	
	// enter the 'book title search' for loop
	for (row = 0; row < NUM_BOOKS; row++)
	{
		// search for a match 
		if (strstr(bookTitle[row], title)) // if they match
		{  
			// display a possible match
			cout << "\nPossible Match Found:  " 
				 << bookTitle[row] 
			     << "\n\n";

			// prompt the user for confirmation
			cout << "Is this a Correct Match?\n";
			cout << "1.Yes\n";
			cout << "2.No\n\n";

			cout << "Enter Your Choice: ";
			cin >> choice;
			
			// validate the user's input
			while (choice != 1 && choice != 2)
			{
				cout << "Please enter a number in the range 1 - 2\n\n";
				cout << "Is this a Correct Match?\n";
				cout << "1.Yes\n";
				cout << "2.No\n\n";

				cout << "Enter Your Choice: ";
				cin >> choice;
			}

			if (choice == 1)
			{  
				// call the 'bookInfo' function to display the results
				bookInfo(isbn[row], bookTitle[row], author[row], publisher[row],
						 dateAdded[row], qtyOnHand[row], wholesale[row], retail[row]);

			// prompt the user to delete the record
			cout << "Would you like to delete this entire record?(Y/N):  ";
			cin >> response;

			// validate the user's input
			while( response != 'y' && response != 'Y' && response != 'n' && response != 'N')
			{
				cout << "\nPlease enter \'Y\' for Yes or \'N\' for No.\n\n";

					cout << "Would you like to delete this entire record?(Y/N):  ";
					cin >> response;
			}

			if (response == 'Y' || response == 'y')
			{
				bookTitle[row][0] = 0;	// the book title becomes an empty row
				isbn	 [row][0] = 0;

				// notify the user that the record has been deleted
				cout << "\nRecord has been deleted.\n";

			} // end if

				break;
			}
			else 
			{
				cout << "\nRecord was not deleted.\n";
				continue;
			}

		}	// end if match found

	}	// end the 'book title search' for loop

	if (row == NUM_BOOKS - 1)
	{
		cout << "\nSorry.  No title matching \'" 
			 << title 
			 << "\' was found."  
			 << "\n\n";
	}	

}  // end function deleteBook

//********************************************
// invMenu function                          *
//********************************************

void invMenu()
{
	int choice = 0; // stores user's choice

	// display the 'Inventory Database Menu' until item 5 is selected
	while (choice != 5)
	{

		// display company name and screen title
		cout << "\n\n\tSerendipity Booksellers\n";
		cout << "\tInventory Database\n\n";

		// display menu items
		cout << "\t\t1.Look Up a Book\n";
		cout << "\t\t2.Add a Book\n";
		cout << "\t\t3.Edit a Book's Record\n";
		cout << "\t\t4.Delete a Book\n";
		cout << "\t\t5.Return to the Main Menu\n\n";

		// display user prompt
		cout << "\t\tEnter Your Choice: ";
		cin >> choice;

		// validate the user's input
		while (choice < 1 || choice > 5)
		{
			cout << "\n\t\tPlease enter a number in the range 1 - 5.\n\n";

			cout << "\t\tEnter Your Choice: ";
			cin >> choice;
		}

		// call the selected function
		switch (choice)
		{ 
			case 1:
				lookUpBook();
					break;

			case 2:
				addBook();
					break;

			case 3:
				editBook();
					break;

			case 4:
				deleteBook();
					break;

			case 5:
				cout << "\n\t\tYou selected item 5.\n";
					break;

		}	// end switch

	}	// end the 'Inventory Database Menu' while loop

	cout << endl << endl;

}	// end function invMenu

