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

using namespace std;

struct Books {
	char title[50];
	char authors[500];
	double price;
	int accNum;
	bool checkOutStatus;
	int claimantId;
};

struct Patron {
	char name[50];
	char address[100];
	int uniqueId;
	int numBooksChkOut;
	int claimdBookAccNum;
};

/* Algorithm for Checking out a Book.
	
		currPatron to check out currBook:
		
		-> Check if currPatron has already checked out 3 books
			-If so, print appropriate message and return
			-Otherwise,
				*If currBook is already checked out, print appropriate message and return
				*Otherwise, if currBook not already claimed by a different patron
					-Increment value of currPatron.numBooksChkdOut
					-Set currBook.checkOutStatus of book to true
				NOTE: Since we want changes to members of currPatron and currBook to persist after currBook is checked out
					  We will need functions with parameters passed by reference.
*/

void checkOutBook(Patron &currPatron, Book &currBook)
{
	//Code with above Algorithm
	if(currPatron.numBooksChkdOut < 3)
	{
		if(currBook.checkOutStatus == true)
		{
			cout << "Sorry! Book " << currBook.title;
			cout << "(Accession # " << currBook.accNum << ")";
			cout << " already checked out!" << endl;
			return;
		}
		else
		{
			if((currBook.claimantId != -1) && (currBook.claimantId != currPatron.uniqueId))
			{
				cout << "Sorry! There is already a pending claim on book";
				cout << currBook.title << "(Acc # " << currBook.accNum << ") ";
				cout << "by a different patron." << endl;
				return;
			}
			else
			{
				currBook.checkOutStatus = true;
				currPatron.numBooksChkdOut++;
				if(currBook.claimantId == currPatron.uniqueId)
				{
					currPatron.claimdBookAccNum = -1;
					currBook.claimantId = -1;
				}
				return;
			}
		}
	}
	else
	{
		cout << "Sorry! Three books have already been checked";
		cout << " out by" << currPatron.name << endl;
	}
}

int main() {
	
	Book libraryShelf[1000];
	Patron libraryPatrons[200];
	
	//checkoutBook(libraryPatron[i], libraryShelf[j]);
	
	return 0;
}