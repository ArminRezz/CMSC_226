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
#include "reports.h"
using namespace std;

const int	 STR_SIZE	 = 51;	// the maximum string size
const int	 NUM_BOOKS	 = 20;	// the number of books in inventory
const int	 NUM_WIDTH	 =  6;	  // the numeric display length
const int	 TITLE_WIDTH = 26;	  // the title display length
const int	 ISBN_WIDTH	 = 14;	  // the ISBN display length
const int	 PRECISION	 =  2;	  // the decimal precision

// The following are external declarations for the various
// arrays used by the program.
extern char bookTitle [NUM_BOOKS][STR_SIZE]; // stores the book title of each book
extern char isbn      [NUM_BOOKS][STR_SIZE]; // stores the isbn number of each book
extern char author    [NUM_BOOKS][STR_SIZE]; // stores the author's name of each book
extern char publisher [NUM_BOOKS][STR_SIZE]; // stores the publisher's name of each book
extern char dateAdded [NUM_BOOKS][STR_SIZE]; // stores the date each book was added

extern int	  qtyOnHand[NUM_BOOKS];      // stores the quantity on hand of each book
extern double wholesale[NUM_BOOKS];          // stores the wholesale price of each book
extern double    retail[NUM_BOOKS];          // stores the retail price of each book

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

