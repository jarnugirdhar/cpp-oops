// LIBRARY INFORMATION MANAGEMENT SYSTEM.


/* NOTE: 1. Assignment operator is valid for struct 
		 2. A way to assign values to object of struct is as follows:
		 	
			Patron currPatron;
			currPatron = {"Jarnu Girdhar", "IIT Goa, India", 2345, 0, -1};
		  
		  	NOTE: The order is same as that of order of members in struct definition.

*/

/* Basic available operations:
	
	1. Checkout: A patron can check out upto 3 books at any time.
	2. Claim: If X has not already checked out 3 books, she can claim a book checked out by Y
				When Y returns the book, it is held for X and cannot be lent to others.
	3. Return: A patron can return a book checked out by her at any time.
	
*/
#include <iostream>
#include <structs.h>
#include <checkout.h>

using namespace std;


int main() {
	
	Book libraryShelf[1000];
	Patron libraryPatrons[200];
	
	//checkoutBook(libraryPatron[i], libraryShelf[j]);
	
	return 0;
}