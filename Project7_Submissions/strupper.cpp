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

#include <cctype>

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