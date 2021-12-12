#include <iostream>
using namespace std;

//Objects of type Mixed will store and manage rational numbers in a
//mixed number format (integer part and a fraction part)
class Mixed
{
	//Overload arithmetic operations
	friend Mixed operator+(const Mixed& a, const Mixed& b);
	friend Mixed operator-(const Mixed& a, const Mixed& b);
	friend Mixed operator*(const Mixed& a, const Mixed& b);
	friend Mixed operator/(const Mixed& a, const Mixed& b);

	//Overload boolean comparison operators
	friend bool operator<(const Mixed& a, const Mixed& b);
	friend bool operator>(const Mixed& a, const Mixed& b);
	friend bool operator<=(const Mixed& a, const Mixed& b);
	friend bool operator>=(const Mixed& a, const Mixed& b);
	friend bool operator==(const Mixed& a, const Mixed& b);
	friend bool operator!=(const Mixed& a, const Mixed& b);

	//Overload insertion and extraction operators
	friend ostream& operator<<(ostream& os, const Mixed& a);
	friend istream& operator>>(istream& is, Mixed& a);

public:
	//Constructors
	Mixed(int n = 0);
	Mixed(int n, int num, int den);

	double Evaluate() const;
	void ToFraction();
	void Simplify();

	//Overload increment and decrement operators
	Mixed& operator++();	// prefix increment
	Mixed operator++(int);	// postfix increment
	Mixed& operator--();	// prefix decrement
	Mixed operator--(int);	// postfix decrement
private:
	int whole;
	int num;
	int den;
};
