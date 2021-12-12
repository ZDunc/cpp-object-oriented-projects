#include <iostream>
#include <iomanip>
#include <cmath>
#include "triangle.h"

using namespace std;

Triangle::Triangle(int s, char b, char f)
/*Triangle constructor that guarantees valid triangle side length and presents
a default character for triangle's border and fill features*/
{
	if(s > 0 & s < 40)
		sideLength = s;
	//error checking side lengths to fit parameters
	else if(s <= 0)
		sideLength = 1;
	else
		sideLength = 39;

	//error checking border for appropriate ASCII values
	if(b >= 33 & b <= 126)
		border = b;
	else
		border = '#';

	 //error checking fill for appropriate ASCII values
	 if(f >= 33 & f <= 126)
 		fill = f;
 	else
 		fill = '*';
}

int Triangle::GetSize() const
//Returns the size/ side length of the triangle
{
	return sideLength;
}

int Triangle::Perimeter() const
//Returns perimeter of triangle
{
	int x = 3*sideLength;
	return x;
}

double Triangle::Area() const
//Returns area of Triangle
{
	cout << fixed << showpoint << setprecision(4);

	double x;
	x = (sqrt(3)/4)*pow(sideLength, 2);

	return x;
}

void Triangle::Grow()
//Grows the triangle side length by 1 as long as it does not exceed 39
{
	if(sideLength < 39)
		sideLength++;
}

void Triangle::Shrink()
/*Shrinks the triangle size by 1 as long as it stays within valid semantic
state*/
{
	if(sideLength > 1)
		sideLength--;
}

void Triangle::SetBorder(char newBorder)
/*changes the border character of triangle as long as it is within valid
ASCII parameters*/
{
	if(newBorder >= 33 & newBorder <= 126)
		border = newBorder;
	else
		border = '#';
}

void Triangle::SetFill(char newFill)
/*changes the fill character of triangle as long as it is within valid
ASCII parameters*/
{
	if(newFill >= 33 & newFill <= 126)
		fill = newFill;
	else
		fill = '*';
}

void Triangle::Draw() const
//Outputs a visual display of the triangle
{
	for (int i = 1; i < sideLength; i++)
    {
        for (int j = i; j < sideLength; j++)
        {
            cout << ' ';
        }

        cout << border << ' ';

        for (int k = sideLength; k > sideLength-i+2; k--)
        {
            cout << fill << ' ';
        }
        if(i == 1)
            cout << "";
        else
            cout << border;

        cout << '\n';
    }

		//Bottom row of triangle
    for (int i = 1; i <= sideLength; i++)
    {
        if(i < sideLength)
            cout << border << ' ';
        else
            cout << border << '\n';
    }
}

void Triangle::Summary() const
/*Displays all information about a triangle: its size, perimeter, area, and a
picture of what it looks like*/
{
	cout << fixed << showpoint << setprecision(2);

	int perimeter = 3*sideLength;
	double area = (sqrt(3)/4)*pow(sideLength, 2);

	cout << "Size of triangle's side = " << sideLength << " units.\n";
	cout << "Perimeter of triangle = " << perimeter << " units.\n";
	cout << "Area of triangle = " << area << " units.\n";
	cout << "Triangle looks like: \n";

	//Draw Triangle
	for (int i = 1; i < sideLength; i++)
    {
        for (int j = i; j < sideLength; j++)
        {
            cout << ' ';
        }

        cout << border << ' ';

        for (int k = sideLength; k > sideLength-i+2; k--)
        {
            cout << fill << ' ';
        }
        if(i == 1)
            cout << "";
        else
            cout << border;

        cout << '\n';
    }

    for (int i = 1; i <= sideLength; i++)
    {
        if(i < sideLength)
            cout << border << ' ';
        else
            cout << border << '\n';
    } //END of drawing triangle
}
