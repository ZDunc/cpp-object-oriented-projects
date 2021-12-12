#include "mixed.h"
//iostream library and using namespace std already in "mixed.h"

//FRIEND FUNCTIONS

//Overload Artihemtic operations for class Mixed
//Overload addition
Mixed operator+(const Mixed& a, const Mixed& b)
{
	Mixed temp1 = a, temp2 = b, temp3;
	temp1.ToFraction();
	temp2.ToFraction();

	temp3.num = (temp1.den*temp2.num) + (temp2.den*temp1.num);
	temp3.den = (temp1.den*temp2.den);
	temp3.whole = 0;
	temp3.Simplify();

	return temp3;
}

//Overload subtraction
Mixed operator-(const Mixed& a, const Mixed& b)
{
	Mixed temp1 = a, temp2 = b, temp3;
	temp1.ToFraction();
	temp2.ToFraction();

	temp3.num = (temp2.den*temp1.num) - (temp1.den*temp2.num);
	temp3.den = (temp1.den*temp2.den);
	temp3.whole = 0;
	temp3.Simplify();

	return temp3;
}

//Overload multiplication
Mixed operator*(const Mixed& a, const Mixed& b)
{
	Mixed temp1 = a, temp2 = b, temp3;
	temp1.ToFraction();
	temp2.ToFraction();

	temp3.num = temp1.num*temp2.num;
	temp3.den = temp1.den*temp2.den;
	temp3.whole = 0;
	temp3.Simplify();

	return temp3;
}

//Overload division
Mixed operator/(const Mixed& a, const Mixed& b)
{
	Mixed temp1 = a, temp2 = b, temp3;
	temp1.ToFraction();
	temp2.ToFraction();

	temp3.num = temp1.num*temp2.den;
	temp3.den = temp1.den*temp2.num;
	if(temp3.den < 0)
	{
		temp3.den = temp3.den*-1;
		temp3.num = temp3.num*-1;
	}
	temp3.whole = 0;
	temp3.Simplify();

	return temp3;
}

//Overload boolean comparison operators
//Overload less than
bool operator<(const Mixed& a, const Mixed& b)
{
	Mixed temp1 = a, temp2 = b;
	temp1.ToFraction();
	temp2.ToFraction();

	if(temp2.den*temp1.num > temp1.den*temp2.num)
		return false;
	else
		return true;
}

//Overload greater than
bool operator>(const Mixed& a, const Mixed& b)
{
	Mixed temp1 = a, temp2 = b;
	temp1.ToFraction();
	temp2.ToFraction();

	if(temp2.den*temp1.num > temp1.den*temp2.num)
		return true;
	else
		return false;
}

//Overload less than or equals to
bool operator<=(const Mixed& a, const Mixed& b)
{
	Mixed temp1 = a, temp2 = b;
	temp1.ToFraction();
	temp2.ToFraction();

	if(temp2.den*temp1.num >= temp1.den*temp2.num)
		return false;
	else
		return true;
}

//Overload greater than or equals to
bool operator>=(const Mixed& a, const Mixed& b)
{
	Mixed temp1 = a, temp2 = b;
	temp1.ToFraction();
	temp2.ToFraction();

	if(temp2.den*temp1.num >= temp1.den*temp2.num)
    		return true;
	else
    		return false;
}

//Overload equals to
bool operator==(const Mixed& a, const Mixed& b)
{
	Mixed temp1 = a, temp2 = b;
	temp1.ToFraction();
	temp2.ToFraction();

	if(temp2.den*temp1.num == temp1.den*temp2.num)
		return true;
	else
		return false;
}

//Overload not equals to
bool operator!=(const Mixed& a, const Mixed& b)
{
	Mixed temp1 = a, temp2 = b;
	temp1.ToFraction();
	temp2.ToFraction();

	if(temp2.den*temp1.num  == temp1.den*temp2.num)
		return false;
	else
		return true;
}

//Overload insertion operator
ostream& operator<<(ostream& os, const Mixed& a)
{
	if(a.whole == 0 && a.num == 0)
		os << "0";
	else if(a.whole != 0 && a.num == 0)
		os << a.whole;
	else if(a.whole == 0 && a.num != 0)
		os << a.num << "/" << a.den;
	else
		os << a.whole << " " << a.num << "/" << a.den;

	return os;
}

//Overload extraction operator
istream& operator>>(istream& is, Mixed& a)
{
	char divi;
	is >> a.whole >> a.num >> divi >> a.den;

	//same error checking as in constructor
	if( (a.whole<0 && a.num<0) || (a.whole<0 && a.den<0)   ||
 	    (a.num<0 && a.den<0)   || (a.whole<0 && a.num<0 && a.den<0) ||
	    (a.num>0 && a.den<0)   || (a.whole>0 && a.den<0)   ||
	    (a.whole>0 && a.num<0) || (a.whole==0 && a.num==0) || (a.den==0) )
	{
		a.whole = 0;
		a.num = 0;
 		a.den = 1;
    	}

	return is;
}

//MEMBER FUNCTIONS

//CONSTRUCTORS
//"n" defaulted to 0 as defined in .h file
//Also acts as a conversion constructor
Mixed::Mixed(int n)
{
	whole = n;
	num = 0;
	den = 1;
}

//Constructor with parameters
Mixed::Mixed(int n, int numer, int denom)
{
	//ERROR CHECKING
	//accounts for ALL incorrect negative number possibilities
	//as well as undefined numbers
	if( (n<0 && numer<0) || (n<0 && denom<0) || (numer<0 && denom<0) ||
	    (n<0 && numer<0 && denom<0) || (numer>0 && denom<0) ||
	    (n>0 && denom<0) || (n>0 && numer<0) || (n==0 && numer==0) ||
	    (denom==0) )
	{
		whole = 0;
		num = 0;
		den = 1;
	}
	else
	{
		whole = n;
		num = numer;
		den = denom;
	}
}

//Returns decimal equivalent of mixed number
double Mixed::Evaluate() const
{
	double a = num, b = den;
	double x;

	if (whole < 0 || num <0)
	{
		x = ((b*whole)-a)/b;
	}
	else
		x = ((b*whole)+a)/b;
	return x;
}

//Converts mixed number into fraction form
void Mixed::ToFraction()
{
	int x;

	if(whole > 0)
	{
		x = (den*whole)+num;
		num = x;
		whole = 0;
	}
	if(whole < 0)
	{
		x = (den*whole)-num;
		num = x;
		whole = 0;
	}
}

//Simplifies mixed number representations to lowest terms
void Mixed::Simplify()
{
	//First, make sure fraction is in correct mixed format

	//Works for both positive and negative improper fractions
	if(num > den || num*-1 > den)
	{
		int x = num, y = den;
		if(num > den)
			num = x%y;
		if(num*-1 > den)
			num = (x%y)*-1;

		whole = (x/y) + whole;
	}

	//Then, reduce fraction to lowest terms
	//Establish Greatest Common Denominator to do so
	int GCD = 1;

	//For loop to find GCD
	//Will only work when num is less than den
	for (int i = 1; i < num+1; i++)
        {
        	if(num%i == 0 && den%i==0)
        	{
        		GCD = i;
       		}
        }

	num = num/GCD;
	den = den/GCD;
}

//Increment and decrement operators
Mixed& Mixed::operator++()    // prefix increment
{
	whole = whole+1;
	return *this;
}

Mixed Mixed::operator++(int)  // postfix increment
{
	Mixed temp = *this;
	whole = whole+1;
	return temp;
}

Mixed& Mixed::operator--()     // prefix decrement
{
	whole = whole-1;
	return *this;
}

Mixed Mixed::operator--(int)  // postfix decrement
{
	Mixed temp = *this;
	whole = whole-1;
	return temp;
}
