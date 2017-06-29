
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
