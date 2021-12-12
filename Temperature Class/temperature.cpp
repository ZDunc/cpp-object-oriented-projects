#include <iostream>
#include <iomanip>
#include <cctype>
#include "temperature.h"

using namespace std;


//Default Constructor
Temperature::Temperature()
{
	temp = 0;
	scale = 'C';
	format = 'D';
}

//Constructor with parameters
Temperature::Temperature(double deg, char s)
{
	s = (char) toupper(s);

	//checks for valid scale
	if(s != 'C' && s != 'F' && s!= 'K')
	{
		scale = 'C';
		temp = 0;
	}
	//checks for valid temperature above absolute zero
	else if((s == 'K' && deg <= 0) || (s == 'C' && deg <= -273.15) || (s == 'F' && deg <= -459.67))
	{
		scale = 'C';
		temp = 0;
	}
	else
	{
		scale = s;
		temp = deg;
	}

	//default display formatting
	format = 'D';
}

//Inputs temperature and scale from user with error checking
void Temperature::Input()
{
	double deg;
	char s;

	cout << "Enter a temperature below, degree and scale (i.e. 0 C)\n";
	cin >> deg >> s;

	s = (char) toupper(s);

	while(s != 'C' && s != 'F' && s!= 'K')
	{
		cout << "Invalid temperature. Try again:\n";
		cin >> deg >> s;
	}

	while((s == 'K' && deg <= 0) || (s == 'C' && deg <= -273.15) || (s == 'F' && deg <= -459.67))
	{
		cout << "Invalid temperature. Try again:\n";
    cin >> deg >> s;
	}

	temp = deg;
	scale = s;
}

//Prints object's temp and scale according to formatting settings
void Temperature::Show() const
{
	if(format == 'D')
		cout << temp << ' ' << scale << '\n';
	if(format == 'P')
	{
		int oldprecision = cout.precision();

		cout << fixed << showpoint << setprecision(1);

		cout << temp << ' ' << scale << '\n';

		cout.precision(oldprecision);
	}
	if(format == 'L')
	{
		cout << temp << ' ';
			if(scale == 'C')
				cout << "Celsuis";
			if(scale == 'F')
				cout << "Farenheit";
			if(scale == 'K')
				cout << "Kelvin";
	}
}

//Sets an objects temp and scale while also returning if it went through
//or not through a return of type bool
bool Temperature::Set(double deg, char s)
{
	s = (char) toupper(s);

  if(s != 'C' && s != 'F' && s!= 'K')
    return false;
  else if((s == 'K' && deg <= 0) || (s == 'C' && deg <= -273.15) || (s == 'F' && deg <= -459.67))
    return false;
	else
	{
		temp = deg;
		scale = s;
		return true;
	}
}

//Accessors
double Temperature::GetDegrees() const
{
	return temp;
}

char Temperature::GetScale() const
{
	return scale;
}

//Changes temperature format, returns bool if format was changed successfully
//or not
bool Temperature::SetFormat(char f)
{
	if(f == 'P' || f == 'L' || f == 'D')
	{
		if(f == 'P')
			format = 'P';
		if(f == 'L')
			format = 'L';
		if(f == 'D')
			format = 'D';
		return true;
	}
	else
		return false;
}

//Converts objects' temperatures between C, F, and K scales
//Returns true or false
bool Temperature::Convert(char sc)
{
	sc = (char) toupper(sc);

	if(scale == 'C' && sc == 'F')
	{
		scale = 'F';
		temp = ((temp*9)/5)+32;
		return true;
	}
	else if(scale == 'F' && sc == 'C')
	{
		scale = 'C';
		temp = ((temp-32)*5)/9;
		return true;
	}
	else if(scale == 'C' && sc == 'K')
	{
		scale = 'K';
		temp = temp + 273.15;
		return true;
	}
	else if(scale == 'K' && sc == 'C')
	{
		scale = 'C';
		temp = temp - 273.15;
		return true;
	}
	else if(scale == 'F' && sc == 'K')
	{
		scale = 'K';
		temp = (((temp-32)*5)/9) + 273.15;
		return true;
	}
	else if(scale == 'K' && sc == 'F')
	{
		scale = 'F';
		temp = (((temp - 273.15)*9)/5)+32;
		return true;
	}
	else
		return false;
}

//Compares degrees of two temperature objects
int Temperature::Compare(const Temperature& d) const
{
		int comp;
		int x, y; 		//local variables storing temp of calling object, x, and
									//parameter object, y

		//makes sure calling object temp is always in Celsuis before comparison
		if(this->scale == 'K')
		{
			x = this->temp;
			x = x - 273.15;
		}
		else if(this->scale == 'F')
		{
			x = this->temp;
			x = ((x-32)*5)/9;
		}
		else
			x = this->temp;

		//makes sure parameter is always in Celsuis before comparison
		if(d.scale == 'K')
		{
			y = d.temp;
			y = y - 273.15;
		}
		else if(d.scale == 'F')
		{
			y = d.temp;
			y = ((y-32)*5)/9;
		}
		else
			y = d.temp;

		if(x > y)
		{
			comp = 1;
			return comp;
		}
		if(x == y)
		{
			comp = 0;
			return comp;
		}
		if(x < y)
		{
			comp = -1;
			return comp;
		}
}
