#include <iostream>
#include <iomanip>
#include "book.h"

using namespace std;

Book::Book() {

    char t[6] = {"BLANK"};
    for (int i = 0; i < 6; i++)
        title[i] = *(t + i);
    char a[6] = {"BLANK"};
    for (int i = 0; i < 6; i++)
        author[i] = *(a + i);
    type = FICTION;
    price = 0;
}

//ERROR CHECKING?
//DELETE OLD ARRAYS
void Book::Set(const char* t, const char* a, Genre g, double p)
{
    for(int i = 0; i < 31; i++)
        title[i] = *(t+i);
    for(int j = 0; j < 21; j++)
        author[j] = *(a+j);
    type = g;
    price = p;
}
// the Set function should allow incoming data to be received through
//  parameters and loaded into the member data of the object.  (i.e.
//  this function "sets" the state of the object to the data passed in).
//  The parameters t, a, g, and p represent the title, author, genre,
//  and price of the book, respectively.

const char* Book::GetTitle() const
// returns the title stored in the object
{
    const char* ch;
    //ch = new char[32];
    ch = title;
    return ch;
}
const char* Book::GetAuthor() const
// returns the author
{
    const char* ch;
    ch = author;
    return ch;
    //return *author;
}

double Book::GetPrice() const
// returns the price
{

    return price;
}

Genre Book::GetGenre() const
// returns the genre
{
    return type;
}

void Book::Display() const
{
    int oldprecision = cout.precision();
    cout << fixed << showpoint << setprecision(2);

    //ADD set precision
    cout << setw(31) << title << setw(21) << author << setw(20);
    if (type == FICTION)
        cout << "FICTION";
    else if (type == MYSTERY)
        cout << "MYSTERY";
    else if (type == SCIFI)
        cout << "SCIFI";
    else if (type == COMPUTER)
        cout << "COMPUTER";
    cout << '$' << price << '\n';

    cout.precision(oldprecision);
}
/* The member function Display() should print out a Book object on one line
as follows, in an organized manner. (Monetary output should be in dollars
and cents notation, to two decimal places):
Title                         Author              Genre         Price

Examples:
Programming for Dummies       Marvin Dipwart      Computer   $  24.95
Mutant Space Weasels          Bob Myers           Sci-Fi     $   5.95

*/
