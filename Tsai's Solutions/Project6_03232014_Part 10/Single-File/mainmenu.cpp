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
// Single-File Program                                    *
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

//********************************************
// cashier function                          *
//********************************************

void cashier()
{
	char	isbnNumber[NUM_BOOKS][STR_SIZE];	// ISBN number of each book ordered
	char	thisTitle [NUM_BOOKS][STR_SIZE];	// title of each book ordered

	int		quantityBooks[NUM_BOOKS];	// quantity of each book ordered
	double	unitPrice	 [NUM_BOOKS];	// unit price of each book ordered
	double	subTotal	 [NUM_BOOKS];	// total of the each order before sales tax
	char	transDate	 [STR_SIZE];	// the transaction date

	double	orderSalesTax	= 0;	// the amount of sales tax for this order
	double	runningTotal	= 0;	// the total of the order before sales tax
	double	grandTotal		= 0;	// the subtotal + sales tax 
	int		validQty		= 0;	// stores quantity of a book before user input

	int		choice			= 0;	// stores the user's choice
	int		counter			= 0;	// counts each new book ordered

	// 'Process Another Transaction' repeats the program until item 2 is selected
	while(choice != 2)	
	{
		counter = 0;		// reset the counter

		// display company name and screen title
		cout << "\n\nSerendipity Booksellers\n";
		cout << " Cashier Module\n\n";

		// enter date of purchase
		cin.ignore();
		cout	<< "Date(MM/DD/YY): ";
		cin.getline(transDate,STR_SIZE);

			// 'Add Another Title' add another title until item 2 is selected
			while(choice != 2)	
			{
				// 'Re-enter ISBN Number' re-enter the ISBN number until item 2 is selected
				while(choice != 2) 
				{
					// prompt the user to enter an ISBN number
					cout << "ISBN(#-###-#####-#): ";
					cin.getline(isbnNumber[counter],STR_SIZE);
				
				// enter the 'search for isbn number' for loop
				for (int row = 0; row < NUM_BOOKS; row++)
				{
					if(strcmp(isbnNumber[counter],isbn[row]) == 0)	// if they match
					{
						// display book information
						cout << "Title: " 
							 << bookTitle[row] 
							 << endl;
					
						cout << fixed 
							 << showpoint 
							 << setprecision(PRECISION) 
							 << "Price: " 
							 << retail[row] 
							 << endl;

						// store book information in local variables
						unitPrice[counter] = retail[row];
						strcpy(thisTitle[counter], bookTitle[row]);
						
						validQty = qtyOnHand[row];	// store quantity before input

						// prompt the user to enter quantity of books
						cout << "Quantity of Book: ";
						cin	 >> quantityBooks[counter];
						cin.ignore();

						// validate user's input
						while(quantityBooks[counter] < 1)
						{
							cout << "\nPlease enter a valid quantity.\n\n";

							cout << "Quantity of Book: ";
							cin	 >> quantityBooks[counter];
							cin.ignore();
						}

						// quantity requested is in inventory
						if(quantityBooks[counter] <= qtyOnHand[row])
						{
							// remove the quantity requested from inventory
							qtyOnHand[row] -= quantityBooks[counter];
						}

						// quantity requested is not in inventory
						else if(quantityBooks[counter] > qtyOnHand[row])
						{
							counter--;	// decrement the counter

							qtyOnHand[row] = validQty;	// restore quantity before input

							cout << "\nSorry, insufficient quantity in stock.\n";
							
							main();		// return to the Main Menu
						}

						// prompt the user to add another title
						cout << "\nAdd another title to this order?\n";
						cout << "1. Yes\n";
						cout << "2. No\n\n";

						cout << "Enter Your Choice: ";
						cin	 >> choice;
						cin.ignore();

						counter++;		// increment the counter

						cout << endl;

						// validate user's input
						while (choice != 1 && choice != 2)
						{
							cout << "\nPlease enter a number in the range 1 - 2.\n\n";

							cout << "\nAdd another title to this order?\n";
							cout << "1. Yes\n";
							cout << "2. No\n\n";

							cout << "Enter Your Choice: ";
							cin	 >> choice;
							cin.ignore();
						}		

						break;

					}	// end if 

					else if(row == NUM_BOOKS - 1)
					{
						cout << "\nISBN number was not found.\n\n";

						cout << "Re-enter ISBN number?\n";
						cout << "1.Yes\n";
						cout << "2.No\n\n";

						cout << "Enter Your Choice: ";
						cin	 >> choice;
						cin.ignore();

						// validate user's input
						while (choice != 1 && choice != 2)
						{
							cout << "\nPlease enter a number in the range 1 - 2.\n\n";

							cout << "\nRe-enter ISBN number?\n";
							cout << "1. Yes\n";
							cout << "2. No\n\n";

							cout << "Enter Your Choice: ";
							cin	 >> choice;
							cin.ignore();
						}	

					}	// end else if 

				}	// end the 'search for isbn number' for loop

				cout << endl;

			}	// end the 'Re-enter ISBN Number' while loop

		}	// end the 'Add Another Title' while loop

			if( counter > 0)	 // verify at least one order exists
			{

			// display company name
			cout << "\n\nSerendipity Book Sellers\n\n";

			// display date
			cout << "Date: " 
				 << transDate 
				 << "\n\n";

			// display headings
			cout << "Qty\tISBN\t\tTitle\t\t\t\tPrice\t\tTotal\n";
			cout << "________________________________________";
			cout << "________________________________________";
			cout << "\n";

			// enter the 'Display Information' for loop
			for (int i = 0; i < counter; i++)
			{
				// perform the calculations
				subTotal[i]		= (quantityBooks[i] * unitPrice[i]);
				orderSalesTax  += (subTotal[i] * SALES_TAX);
				runningTotal   +=  subTotal[i];
				grandTotal		= (orderSalesTax + runningTotal);

				// display order information
				cout << fixed 
					 << showpoint 
					 << right 
					 << setprecision(PRECISION);

				cout << quantityBooks[i] 
					 << "\t";

				cout << left 
					 << setw(ISBN_WIDTH) 
					 << isbnNumber[i] 
					 << "\t";

				cout << left 
					 << setw(TITLE_WIDTH) 
					 << thisTitle[i] 
					 << "\t$ ";

				cout << fixed 
					 << showpoint 
					 << right;

				cout << setw(NUM_WIDTH) 
					 << unitPrice[i] 
					 << "\t$ ";

				cout << setw(NUM_WIDTH) 
					 << subTotal[i];

			}	// end the 'Display Information' for loop

			cout << "\n\n\n";

			// display footer information
			cout << "\t\t\tSubtotal\t\t\t\t\t$ " 
				 << setw(NUM_WIDTH) 
				 << setprecision(PRECISION) 
				 << fixed 
				 << runningTotal 
				 << "\n";

			cout << "\t\t\tTax\t\t\t\t\t\t$ " 
				 << setw(NUM_WIDTH) 
				 << setprecision(PRECISION) 
				 << fixed 
				 << orderSalesTax 
				 << "\n";

			cout << "\t\t\tTotal\t\t\t\t\t\t$ "
				 << setw(NUM_WIDTH) 
				 << setprecision(PRECISION) 
				 << fixed 
				 << grandTotal 
				 << "\n\n";

			cout << "Thank You for Shopping at Serendipity!\n";
	
			cout << endl << endl;

			}	// end 'Order verification' if

		// prompt the user to enter another transaction
		cout << "\nProcess another transaction?\n";
		cout << "1. Yes\n";
		cout << "2. No\n\n";

		cout << "Enter Your Choice: ";
		cin	 >> choice;

		// validate user's input
		while (choice != 1 && choice != 2)
		{
			cout << "\nPlease enter a number in the range 1 - 2.\n\n";

			cout << "\nProcess another transaction?\n";
			cout << "1. Yes\n";
			cout << "2. No\n\n";

			cout << "Enter Your Choice: ";
			cin	 >> choice;
		} 

	}	// end the 'Process Another Transaction' while loop

	cout << endl << endl;

}	// end cashier function
			
//********************************************
// lookUpbook function                       *
//********************************************

void lookUpBook()
{
	char title[STR_SIZE];	// stores a book title the user enters
	int  choice = 0;		// stores the user's numeric choice

	// prompt the user to enter a full or partial book title
	cin.ignore();
	cout << "\nPlease enter all or part of the title:  ";
	cin.getline(title, STR_SIZE);

	strUpper(title);		// Convert to uppercase
	
	// enter the 'book title search' for loop
	for (int row = 0; row < NUM_BOOKS; row++)
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

	// prompt the user to enter a full or partial book title
	cin.ignore();
	cout << "\nPlease enter all or part of the title:  ";
	cin.getline(title, STR_SIZE);

	strUpper(title);		// Convert to uppercase
	
	// enter the 'book title search' for loop
	for (int row = 0; row < NUM_BOOKS; row++)
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

	// prompt the user to enter a full or partial book title
	cin.ignore();
	cout << "\nPlease enter all or part of the title:  ";
	cin.getline(title, STR_SIZE);

	strUpper(title);		// Convert to uppercase
	
	// enter the 'book title search' for loop
	for (int row = 0; row < NUM_BOOKS; row++)
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

//********************************************
// bookInfo function                         *
//********************************************

void bookInfo(char isbn[STR_SIZE], char title[STR_SIZE], char author[STR_SIZE], 
			  char publisher[STR_SIZE], char date[STR_SIZE], int qty,
			  double wholeSale, double retail)
{
	// display company name and screen title
	cout << "\t\t\tSerendipity Booksellers\n";
	cout << "\t\t\t    Book Information\n\n";

	// display information items
	cout << "ISBN: " 
		 << isbn 
		 << "\n";

	cout << "Title: " 
		 << title 
		 << "\n";

	cout << "Author: " 
		 << author 
		 << "\n";

	cout << "Publisher: " 
		 << publisher 
		 << "\n";

	cout << "Date Added: " 
		 << date	
		 << "\n";

	cout << "Quantity-On-Hand: " 
		 << qty 
		 << "\n";

	cout << "Wholesale Cost: " 
		 << fixed 
		 << showpoint 
		 << setprecision(PRECISION) 
		 << wholeSale	
		 << "\n";

	cout << "Retail Price: " 
		 << fixed 
		 << showpoint 
		 << setprecision(PRECISION) 
		 << retail 
		 << "\n";

	cout << endl << endl;

}	// end function bookInfo

//********************************************
// repListing function                       *
//********************************************

void repListing()
{
	char repDate[STR_SIZE];	// stores today's date

	// prompt the user to enter today's date
	cout << "\n\nEnter Today's Date(MM/DD/YY): ";
	cin >> repDate;

	cout << endl << endl;

	// display company name
	cout << "\n\n\t\tSerendipity Booksellers Inventory Listing\n\n";

	// display date
	cout << "Date:\t\t\t" 
		 << repDate;
		
	// display inventory information by record, then by field
	char end[] = {'\0'};

	for (int i = 0; i < NUM_BOOKS; i++)
	{ 
		if (strcmp(isbn[i], end) != 0 ) // do not print an empty record
		{
			cout << "\n_____________________________________________________";

			cout << "\n\nTitle:\t\t\t" 
					<< bookTitle[i];

			cout << "\nISBN:\t\t\t" 
					<< isbn[i]; 

			cout << "\nAuthor:\t\t\t" 
					<< author[i];

			cout << "\nPublisher:\t\t" 
					<< publisher[i];

			cout << "\nDate Added:\t\t" 
				 << dateAdded[i];

			cout << fixed 
					<< showpoint 
					<< right 
					<< setprecision(PRECISION);

			cout << "\nQuantity On Hand:\t"
					<< qtyOnHand[i];

			cout << "\nWholesale Cost:\t\t" 
					<< wholesale[i];

			cout << "\nRetail Price:\t\t" 
					<< retail[i];
		}
	}

	cout << "\n\n_____________________________________________________";
	cout << "\n\nEnd of Inventory Report.\n\n\n";

	// Pause so that user can read report
	cout << "Press Enter to continue...";
	cin.ignore();
	cin.get();
}

//********************************************
// repWholesale function                     *
//********************************************

void repWholesale()
{
	char repDate[STR_SIZE];	// stores today's date

	// prompt the user to enter today's date
	cout << "\n\nEnter Today's Date(MM/DD/YY): ";
	cin >> repDate;

	cout << endl << endl;

	// display header
	cout << "\n\n\t\t\tSerendipity Booksellers\n";
	cout << "\t\t\tWholesale Value Listing\n\n";

	// display date
	cout << "\tDate: " 
			<< repDate
			<< endl;
	
	// display item headings
	cout << "\n\tTitle\t\t\t  ISBN\t\tQuantity\tWholesale\n";
	cout << "\t_________________________________________________________________\n\n";

	double	itemSubTot	= 0;
	double	subTot		= 0;
	char	end[]		= {'\0'};

	for (int i = 0; i < NUM_BOOKS; i++)
	{ 
		if (strcmp(isbn[i], end) != 0 ) // do not print empty records
		{
			cout << "\n\t" 
				 << left
				 << setw(TITLE_WIDTH)
				 << bookTitle[i]; 
				
			cout << left
				 << setw(ISBN_WIDTH)
				 << isbn[i]; 

			cout << right
				 << setw(NUM_WIDTH)
				 << qtyOnHand[i] 
				 << "\t";

			cout << fixed 
				 << showpoint 
				 << right 
				 << setprecision(PRECISION);

			cout << setw(NUM_WIDTH) 
				 << "\t$ "
				 << wholesale[i];

			itemSubTot = qtyOnHand[i] * wholesale[i];
			subTot += itemSubTot;
		}
	}

	cout << "\n\n\n\tTotal Wholesale Value:  $ " 
		 << subTot 
		 << endl;

	cout << "\t_________________________________________________________________\n";

	cout << "\n\tEnd of Wholesale Report.\n\n\n";

	// Pause so that user can read report
	cout << "Press Enter to continue...";
	cin.ignore();
	cin.get();
}

//********************************************
// repRetail function                        *
//********************************************

void repRetail()
{
	char repDate[STR_SIZE];	// stores today's date

	// prompt the user to enter today's date
	cout << "\n\nEnter Today's Date(MM/DD/YY): ";
	cin >> repDate;

	cout << endl << endl;

	// display header
	cout << "\n\n\t\t\tSerendipity Booksellers\n";
	cout << "\t\t\t  Retail Value Listing\n\n";
			
	// display date
	cout << "\tDate: " 
		 << repDate 
		 << endl;
		
	// display item headings
	cout << "\n\tTitle\t\t\t  ISBN\t\tQuantity\tRetail\n";
	cout << "\t_________________________________________________________________\n\n";

	double	itemSubTot	= 0;
	double	subTot		= 0;
	char	end[]		= {'\0'};

	for (int i = 0; i < NUM_BOOKS; i++)
	{ 
		if (strcmp(isbn[i], end) != 0 ) // do not print empty records
		{
			cout << "\n\t" 
				 << left
				 << setw(TITLE_WIDTH)
				 << bookTitle[i]; 

			cout << left
				 << setw(ISBN_WIDTH)
				 << isbn[i]; 

			cout << fixed 
				 << showpoint 
				 << right 
				 << setprecision(PRECISION);

			cout << right
				 << setw(NUM_WIDTH)
				 << qtyOnHand[i] 
				 << "\t";

			cout << setw(NUM_WIDTH) 
				 << "\t$ "
				 << retail[i];

			itemSubTot = qtyOnHand[i] * retail[i];
			subTot += itemSubTot;
		}
	}
	
	cout << "\n\n\n\tTotal Retail Value:  $" << subTot << endl;
	cout << "\t_________________________________________________________________\n\n";
	cout << "\n\tEnd of Retail Report.\n\n\n";
	
	// Pause so that user can read report
	cout << "Press Enter to continue...";
	cin.ignore();
	cin.get();
}

//********************************************
// repQty function                           *
//********************************************

void repQty()
{
	int	 id	   [NUM_BOOKS];		// array to track original order of subscripts
	int* idPtr [NUM_BOOKS];		// pointer to tracking array
	int* qtyPtr[NUM_BOOKS];		// array of pointers to qtyOnHand array

	for(int i = 0; i < NUM_BOOKS; i++)
	{
		id[i]		= i;
		idPtr[i]	= &id[i];
		qtyPtr[i]	= &qtyOnHand[i];
	}
	
	// selection sort to place qtyOnHand in descending order
	// ...and track original subscripts to correspond
	// ...with Title and isbn in parallel arrays

	int  startScan; 
	int	 maxIndex; 
	int* tempId;
	int* maxValue;

	for (startScan = 0; startScan < NUM_BOOKS - 1; startScan++)
	{
		maxIndex = startScan;
		maxValue = qtyPtr[startScan];
		tempId = idPtr[startScan];
		for (int index = startScan + 1; index < NUM_BOOKS; index++)
		{
			if (*(qtyPtr[index]) > *maxValue)
			{
				maxValue = qtyPtr[index];
				tempId	 = idPtr [index];
				maxIndex = index;
			}
		}
		qtyPtr	[maxIndex]	= qtyPtr[startScan];
		idPtr	[maxIndex]	= idPtr	[startScan];
		qtyPtr	[startScan] = maxValue;
		idPtr	[startScan] = tempId;
	}

	char repDate[STR_SIZE];	// stores today's date

	// prompt the user to enter today's date
	cout << "\n\nEnter Today's Date(MM/DD/YY): ";
	cin >> repDate;

	cout << endl << endl;

	// display header
	cout << "\n\n\t\t\tSerendipity Booksellers\n";
	cout << "\t\t\t  Quantity Listing\n\n";

	// display date
	cout << "\tDate: " << repDate << endl;
		
	// display item headings

	cout << "\n\tTitle\t\t\t  ISBN\t\tQuantity\n";
	cout << "\t_______________________________________________________\n";
	char end[] = {'\0'};

	for (int j = 0; j < NUM_BOOKS; j++)
	{ 
		if (strcmp(isbn[*(idPtr[j])], end) != 0 ) // do not print empty records
		{
			cout << "\n\t" 
				 << left
				 << setw(TITLE_WIDTH)
				 << bookTitle[*(idPtr[j])];

			cout << left
				 << setw(ISBN_WIDTH)
				 << isbn[*(idPtr[j])];

			cout << right
				 << setw(NUM_WIDTH)
				 << *qtyPtr[j] 
				 << "\n";
		}
	}
	cout << "\t_______________________________________________________\n";
	cout << "\n\tEnd of Quantity Report.\n\n\n";

	// Pause so that user can read report
	cout << "Press Enter to continue...";
	cin.ignore();
	cin.get();
}

//********************************************
// repCost function                          *
//********************************************

void repCost()
{
	int		id[NUM_BOOKS];			// array to track original order of subscripts
	int*	idPtr[NUM_BOOKS];		// pointer to tracking array
	double* wholePtr[NUM_BOOKS];	// array of pointers to wholesale array

	for(int i = 0; i < NUM_BOOKS; i++)
	{
		id[i]		= i;
		idPtr[i]	= &id[i];
		wholePtr[i] = &wholesale[i];
	}
	
	// selection sort to place Wholesale Cost in descending order
	// ...and track original subscripts to correspond
	// ...with Title, isbn, and qtyOnHand in parallel arrays

	int     startScan; 
	int     maxIndex; 
	int*    tempId;
	double* maxValue;

	for (startScan = 0; startScan < NUM_BOOKS - 1; startScan++)
	{
		maxIndex = startScan;
		maxValue = wholePtr[startScan];
		tempId = idPtr[startScan];
		for (int index = startScan + 1; index < NUM_BOOKS; index++)
		{
			if (*(wholePtr[index]) > *maxValue)
			{
				maxValue	= wholePtr[index];
				tempId		= idPtr[index];
				maxIndex	= index;
			}
		}

		wholePtr[maxIndex]	= wholePtr[startScan];
		idPtr[maxIndex]		= idPtr[startScan];
		wholePtr[startScan] = maxValue;
		idPtr[startScan]	= tempId;
	}

	char repDate[STR_SIZE];	// stores today's date

	// prompt the user to enter today's date
	cout << "\n\nEnter Today's Date(MM/DD/YY): ";
	cin >> repDate;

	cout << endl << endl;

	// display header
	cout << "\n\n\t\t\tSerendipity Booksellers\n";
	cout << "\t\t\t    Cost Listing\n\n";

	// display date
	cout << "\tDate: " 
		 << repDate 
		 << endl;
		
	// display item headings
	cout << "\n\tTitle\t\t\t  ISBN\t\tQuantity\tWholesale\n";
	cout << "\t_________________________________________________________________\n\n";

	char end[] = {'\0'};

	for (int j = 0; j < NUM_BOOKS; j++)
	{ 
		if (strcmp(isbn[*(idPtr[j])], end) != 0 ) // do not print empty records
		{
			cout << "\t" 
				 << left
				 << setw(TITLE_WIDTH)
				 << bookTitle[*(idPtr[j])];

			cout << left
				 << setw(ISBN_WIDTH)
				 << isbn[*(idPtr[j])];

			cout << fixed 
				 << showpoint 
				 << right 
				 << setprecision(PRECISION);

			cout << right
				 << setw(NUM_WIDTH)
				 << qtyOnHand[*(idPtr[j])];

			cout << setw(NUM_WIDTH) 
				 << "\t$ "
				 << *wholePtr[j] 
				 << "\n";
		}
	}

	cout << "\t_________________________________________________________________\n";
	cout << "\n\tEnd of Cost Report.\n\n\n";

	// Pause so that user can read report
	cout << "Press Enter to continue...";
	cin.ignore();
	cin.get();
}

//********************************************
// repAge function                           *
//********************************************

void repAge()
{
	int id[NUM_BOOKS];		  // array to track original order of subscripts
	int* idPtr[NUM_BOOKS];   // pointer to tracking array
	char* datePtr[NUM_BOOKS];  // array of pointers to dateAdded array

	for(int i = 0; i < NUM_BOOKS; i++)
	{
		id[i] = i;
		idPtr[i] = &id[i];
		datePtr[i] = dateAdded[i];
	}
	
	// selection sort to place DateAdded in descending order
	// ...and track original subscripts to correspond
	// ...with Title, isbn, and qtyOnHand in parallel arrays

	int     startScan; 
	int     maxIndex; 
	int*    tempId;
	char*   maxValue;

	for (startScan = 0; startScan < NUM_BOOKS - 1; startScan++)
	{
		maxIndex = startScan;
		maxValue = datePtr[startScan];
		tempId = idPtr[startScan];
		for (int index = startScan + 1; index < NUM_BOOKS; index++)
		{
			if (strcmp(datePtr[index], maxValue) > 0)
			{
				maxValue	= datePtr[index];
				tempId		= idPtr[index];
				maxIndex	= index;
			}
		}

		datePtr[maxIndex]	= datePtr[startScan];
		idPtr[maxIndex]		= idPtr[startScan];
		datePtr[startScan]  = maxValue;
		idPtr[startScan]	= tempId;
	}

	char repDate[STR_SIZE];	// stores today's date

	// prompt the user to enter today's date
	cout << "\n\nEnter Today's Date(MM/DD/YY): ";
	cin >> repDate;

	cout << endl << endl;

	// display header
	cout << "\n\n\t\t\tSerendipity Booksellers\n";
	cout << "\t\t\t    Age Listing\n\n";

	// display date
	cout << "\tDate: " 
		 << repDate 
		 << endl;
		
	// display item headings
	cout << "\n\tTitle\t\t\t  ISBN\t\tQuantity\tDate Added\n";
	cout << "\t_________________________________________________________________\n\n";

	char end[] = {'\0'};

	for (int j = 0; j < NUM_BOOKS; j++)
	{ 
		if (strcmp(isbn[*(idPtr[j])], end) != 0 ) // do not print empty records
		{
			cout << "\t" 
				 << left
				 << setw(TITLE_WIDTH)
				 << bookTitle[*(idPtr[j])];

			cout << left
				 << setw(ISBN_WIDTH)
				 << isbn[*(idPtr[j])];

			cout << fixed 
				 << showpoint 
				 << right 
				 << setprecision(PRECISION);

			cout << right
				 << setw(NUM_WIDTH)
				 << qtyOnHand[*(idPtr[j])];

			cout << setw(NUM_WIDTH) 
				 << "\t"
				 << dateAdded[*(idPtr[j])] 
				 << "\n";
		}
	}

	cout << "\t_________________________________________________________________\n";
	cout << "\n\tEnd of Age Report.\n\n\n";

	// Pause so that user can read report
	cout << "Press Enter to continue...";
	cin.ignore();
	cin.get();
}

//********************************************
// reports function                          *
//********************************************

void reports()
{
	int choice = 0; // stores user's choice

	// display the 'Reports Menu' until item 7 is selected
	while (choice != 7)
	{
		// display company name and screen title
		cout << "\n\n\t\t\tSerendipity Booksellers\n";
		cout << "\t\t\t\tReports\n\n";

		// display information items
		cout << "\t\t1.Inventory Listing\n";
		cout << "\t\t2.Inventory Wholesale Value\n";
		cout << "\t\t3.Inventory Retail Value\n";
		cout << "\t\t4.Listing by Quantity\n";
		cout << "\t\t5.Listing by Cost\n";
		cout << "\t\t6.Listing by Age\n";
		cout << "\t\t7.Return to the Main Menu\n\n";

		// display user prompt
		cout << "\t\tEnter Your Choice: ";
		cin >> choice;

		// validate the user's input
		while (choice < 1 || choice > 7)
		{
			cout << "\n\t\tPlease enter a number in the range 1 - 7.\n";

			cout << "\t\tEnter Your Choice: ";
			cin >> choice;
		}

		// call the selected function
			switch (choice)
			{ 
				case 1:
					repListing();
						break;

				case 2:
					repWholesale();
						break;

				case 3:
					repRetail();
						break;

				case 4:
					repQty();
						break;

				case 5:
					repCost();
						break;
				case 6:
					repAge();
						break;

				case 7:
					cout << "\n\t\tYou selected item 7.\n";
						break;

			}	// end switch

	}	// end the 'Reports Menu' while loop

	cout << endl << endl;

}	// end function reports

//********************************************
// strUpper function                         *
//********************************************

void strUpper(char* str)
{
	while( *str != 0 )
	{
		*str = toupper(*str);
		str++;
	}
}
