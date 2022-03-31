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
#include <iomanip>
#include "cashier.h"
using namespace std;

const int	 STR_SIZE	 = 51;	  // the maximum string size
const int	 NUM_WIDTH	 =  6;	  // the numeric display length
const int	 TITLE_WIDTH = 26;	  // the title display length
const int	 ISBN_WIDTH	 = 14;    // the ISBN display length
const int	 NUM_BOOKS	 = 20;    // the number of books in inventory
const int	 PRECISION	 =  2;	  // the decimal precision
const double  SALES_TAX	 =  0.06; // the rate of the sales tax

// The following are external declarations for the various
// arrays used by the program.
extern char   bookTitle [NUM_BOOKS][STR_SIZE];	// stores the book title of each book
extern char   isbn      [NUM_BOOKS][STR_SIZE];	// stores the isbn number of each book
extern int    qtyOnHand [NUM_BOOKS];            // stores the quantity on hand of each book
extern double retail    [NUM_BOOKS];            // stores the retail price of each book

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
							
							return;		// return to the Main Menu
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
			
