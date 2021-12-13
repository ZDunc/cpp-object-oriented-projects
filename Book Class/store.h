#include "book.h"

class Store
{
public:
	//constructor
	explicit Store(double initial);

	//destructor
	~Store();

	//mutators
	void Insert();
	void Insert(Book temp);
	void Sell(char title[]);
	void Grow();

	//accessors
	void DisplayInventory() const;
	int FindTitle(char* name, int null) const;
	void Find(char* name) const;
	void GenreSummary(char ch) const;
	double GetBalance() const;

	//print
	void PrintMenu() const;

private:
	double registerBalance;

	int currentSize;
	int maxSize;
	Book* bookList;
};
