/* Structures for LIBRARY MANAGEMENT SYSTEM */

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