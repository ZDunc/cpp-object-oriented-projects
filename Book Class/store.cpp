#include <iostream>
#include <cstring>
#include <iomanip>
#include "store.h"
#include "book.h"

using namespace std;

//Constructor creates empty inventory of books
Store::Store(double initial)
{
	currentSize = 0;
	maxSize = 5;
	bookList = new Book[maxSize];

	registerBalance = initial;
}

//destructor
Store::~Store()
{
	delete [] bookList;
}

//mutator functions
void Store::Insert()
{
	if (currentSize == maxSize)
 		Grow();

  //ONLY first step in insert function
}

void Store::Insert(Book temp)
{
	bookList[currentSize++] = temp;
}

void Store::Sell(char title[])
{
	int null = 0;
	int thisEntry = FindTitle(title, null);
	if (thisEntry == -1)
		cout << title << " not found in inventory";
	else
	{
		registerBalance = registerBalance + bookList[thisEntry].GetPrice();
		for (int i = thisEntry + 1; i < currentSize; i++)
			bookList[i - 1] = bookList[i];

		currentSize--;
		cout << "Entry removed.\n";
	}
}

void Store::Grow()
{
	maxSize = currentSize + 5;

	//make entirely new array to then transfer over data
	Book* newList = new Book[maxSize];
	for (int i = 0; i < currentSize; i++)
		newList[i] = bookList[i];

	//remove old array and repurpose old pointer name to new array
	delete [] bookList;
	bookList = newList;

	cout << "Array is being re-sized to accomodate 5 more slots.";
}

//accessor functions
void Store::DisplayInventory() const
{
	if (currentSize == 0)
   	{
		cout << "\nCurrent inventory is empty.\n";
		return;
   	}

   	// Display a header.
   	cout << left << setw(31) << "\n***TITLE***" << setw(21) << "***AUTHOR***"
		     << setw(20) << "***GENRE***" << setw(20) << "***PRICE***\n";

   	for (int i = 0; i < currentSize; i++)	// For each entry,
		bookList[i].Display();			// send it to output

	cout << "\n\nTotal Number of books: " << currentSize << '\n';

	double sumInventory = 0;
	for (int i = 0; i < currentSize; i++)
		sumInventory = bookList[i].GetPrice() + sumInventory;

	cout << "Total cost of books in inventory: " << '$' << sumInventory << '\n';
}

int Store::FindTitle(char* name, int null) const
{
	//Null NOT needed for function but was used to accomodate appropriate
	//function overloading.
	for (int i = 0; i < currentSize; i++)   // Look at each entry.
        {
                if (strcmp(bookList[i].GetTitle(), name) == 0)
                        return i;
	}
	return -1;
}

void Store::Find(char* name) const
{
 	for (int i = 0; i < currentSize; i++)	// Look at each entry.
	{
		if (strcmp(bookList[i].GetTitle(), name) == 0)
		{
			bookList[i].Display();
			return;
		}
	}

	for (int j = 0; j < currentSize; j++)   // Look at each entry.
	{
		if (strcmp(bookList[j].GetAuthor(), name) == 0)
		{
			bookList[j].Display();
			cout << '\n';
			if (j == currentSize - 1)
				return;
		}
	}

	cout << '\n' << name << " not found in current inventory.\n";
}

void Store::GenreSummary(char ch) const
{
	Genre temp;

	if (ch == 'F')
		temp = FICTION;
	else if (ch == 'M')
		temp = MYSTERY;
	else if (ch == 'S')
		temp = SCIFI;
	else if (ch == 'C')
		temp = COMPUTER;

	if (currentSize == 0)
        {
                cout << "\nCurrent inventory is empty.\n";
                return;
        }

	if (currentSize > 0)
        	// Display a header.
        	cout << "\n\t***TITLE***\t\t***AUTHOR***\t\t***GENRE***\t\t***PRICE***\n\n";

        for (int i = 0; i < currentSize; i++)   // For each entry
	{
		if (bookList[i].GetGenre() == temp)
                	bookList[i].Display();
	}
}

double Store::GetBalance() const
{
	return registerBalance;
}

//print function
void Store::PrintMenu() const
{
	cout << "\t     ***BOOKSTORE MENU***\n"
	     << "\tA:   Add a book to inventory\n"
	     << "\tF:   Find a book from inventory\n"
	     << "\tS:   Sell a book\n"
	     << "\tD:   Display the inventory list\n"
	     << "\tG:   Genre summary\n"
	     << "\tM:   Show this Menu\n"
	     << "\tX:   Exit the program\n";
}
