#include "store.h"
#include "book.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cctype>

using namespace std;

int main()
{
	double initial;

	int oldprecision = cout.precision();
	cout << fixed << showpoint << setprecision(2);

	cout << "\n***Welcome to Bookstore Inventory Manager***\n";
	cout << "Please input the starting money in the cash register: ";
	cin >> initial;

	cout << "\n\n";
	Store BooksForYou(initial);
        char choice;

	BooksForYou.PrintMenu();

	do
	{
        	cout << "\nSelect an option. \n> ";
        	cin >> choice;
					cin.ignore();

		choice = (char) toupper(choice);

		switch (choice)
		{
			case 'A':
			{
				Book temp;
                		Genre temp2;
                		char t[31];
                		char a[21];
                		char g;
                		double p;

                		BooksForYou.Insert();

				cout << "Enter title: ";
				cin.getline(t, 31);
				cout << "Enter author: ";
				cin.getline(a, 21);
				cout << "Enter Genre - (F)iction, (M)ystery, (S)ci-Fi"
				<< "or (C)omputer: ";
				cin >> g;
				cout << "Enter price: ";
				cin >> p;
				cin.ignore();

				cout << '\n';

                		g = (char) toupper(g);

                		if (g == 'F')
                    			temp2 = FICTION;
                		else if (g == 'M')
                    			temp2 = MYSTERY;
                		else if (g == 'S')
                    			temp2 = SCIFI;
                		else if (g == 'C')
                    			temp2 = COMPUTER;
                		temp.Set(t, a, temp2, p);

                		BooksForYou.Insert(temp);
                		break;
			}
			case 'F':
			{
				cout << "Enter search string (title or author): ";

				char name[31];
				cin.getline(name, 31);

				BooksForYou.Find(name);
				break;
			}
			case 'S':
			{
				//Ask user to type in title of book
				cout << "Enter the title of the book you"
				     << " would like to purchase.\n";
				char title[31];
				cin.getline(title, 31);

				BooksForYou.Sell(title);
				break;
			}
			case 'D':
			{
				BooksForYou.DisplayInventory();
                                break;
			}
			case 'G':
			{
				//Ask user to input genre
				cout << "Enter Genre - (F)iction, (M)ystery,"
				     << "(S)ci-Fi, or (C)omputer: ";
				char ch;
				cin >> ch;
				cin.ignore();

				ch = (char) toupper(ch);

				//Error checking
				while(ch != 'F' && ch != 'M' && ch != 'S' && ch != 'C')
				{
					cout << "Invalid entry. Try again: ";
					cin >> ch;
					cin.ignore();
					ch = (char) toupper(ch);
				}

				BooksForYou.GenreSummary(ch);
				break;
			}
			case 'M':
			{
				BooksForYou.PrintMenu();
				break;
			}
			case 'X':
				break;
			default:
			{
				cout << "Invalid option. Try again.\n";
				break;
			}

		}//end of switch statement for menu

	}while(choice != 'X'); //end of do-while loop

	cout << "\nTotal balance of cash register is now: "
	     << '$' << BooksForYou.GetBalance() << '\n';

	cout.precision(oldprecision);

	return 0;
}
