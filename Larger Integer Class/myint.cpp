#include "myint.h"
#include <iostream>
#include <cstring>

using namespace std;

//FRIEND FUNCTIONS
//Overload arithmetic operations first

//Addition
MyInt operator+(const MyInt& a, const MyInt& b)
{
    MyInt temp1 = a, temp2 = b, temp3;
    unsigned int current = 0, notCurrent = 0, max = 0;
    int x = 0;
    bool larger;

    //Establishing variable used in for loop
    //Looking for the LARGER of the two MyInts
    if (temp1.current >= temp2.current)
    {
        current = temp1.current;
        notCurrent = temp2.current;
        max = temp1.max;
        larger = true;
    }
    else
    {
        current = temp2.current;
        notCurrent = temp1.current;
        max = temp2.max;
        larger = false;
    }

    //Set a temp MyInt with the larger array size
    temp3.current = current;
    temp3.max = max;

    for (int i = 0; i < current; i++)
    {
        if(i < notCurrent) // digits added and assigned to temp3 until lower-digit number
                           // is fully added to higher digit number
        {
            x = (temp1.arr[(temp1.current)-1-i] - '0') +
                (temp2.arr[(temp2.current)-1-i] - '0') + x;

            if(x < 10)
            {
                temp3.arr[current-1-i] = static_cast<char> (x) + '0';
                x = 0;
            }
            else
            {
                temp3.arr[current-1-i] = static_cast<char> (x - 10) + '0';
                x = 1;
            }
        }
        else //WHEN lower digit number is fully added
             //and remaining digits in larger number need to be assigned to temp3
        {
            if (larger)
                temp3.arr[current-1-i] = static_cast<char> ((temp1.arr[current-1-i] - '0') + x) + '0';
            else
                temp3.arr[current-1-i] = static_cast<char> ((temp2.arr[current-1-i] - '0') + x) + '0';

            x = 0;
        }

        //CODE FOR POTENTIAL FINAL REMAINDER - if array needs to be increased
        if(i == current-1 && x == 1) //if on last round of for loop and there is still a remainder
        {
            MyInt temp4;
            temp4.current = current + 1;
            temp4.max = max + 1;
            temp4.arr[0] = static_cast<char> (1) + '0';
            for(int j = 1; j < current + 1; j++)
            {
                temp4.arr[j] = temp3.arr[j-1];
            }

            return temp4;
        }
    }

    return temp3;
}

//Overload boolean comparison operators
bool operator<(const MyInt& a, const MyInt& b)
{
    if (a.current < b.current)
        return true;
    else if(a.current > b.current)
        return false;
    else
    {
        //current will be equivalent for a and b
        for (int i = 0; i < a.current; i++)
        {
            if(a.arr[i] < b.arr[i])
                return true;
            if(a.arr[i] > b.arr[i])
                return false;
        }

        //If they proved to be even
        return false;
    }
}

bool operator>(const MyInt& a, const MyInt& b)
{
    if (a < b)
      return false;
    else
      return true;
}

bool operator<=(const MyInt& a, const MyInt& b)
{
    if (a > b)
      return false;
    else
      return true;
}

bool operator>=(const MyInt& a, const MyInt& b)
{
    if (a < b)
      return false;
    else
      return true;
}

bool operator==(const MyInt& a, const MyInt& b)
{
    if (a.current != b.current)
        return false;

    //current will be equivalent for a and b
    for (int i = 0; i < a.current; i++)
    {
        if(a.arr[i] != b.arr[i])
            return false;
    }

    //If inequality was not proved
    return true;
}

bool operator!=(const MyInt& a, const MyInt& b)
{
    if (a == b)
      return false;
    else
      return true;
}

//Overload Input and Output Streams
ostream& operator<<(ostream& os, const MyInt& a)
{
    if(a.current == 0)
    {
        os << 0;
        return os;
    }

    //Print out every index
    for(int i = 0; i < a.current; i++)
        os << (a.arr[i]);

    return os;
}

istream& operator>>(istream& is, MyInt& a)
{
    // Reinitialize MyInt a to 0
    MyInt x;
    a = x;

    while(is.peek() == 32) //Ignore ASCII Value for Space
        is.ignore();

    // Read consecutive digits until a nondigit is encountered
    int counter = 0;
    while (! is.eof() )
    {
        if(a.current == a.max)
            a.Grow();

        if (is.peek() >= 48 && is.peek() <= 57) //Note ASCII values for 0-9
        {
            is >> a.arr[counter];
            a.current++;
            cout << "a.arr[" << counter << "] is set to " << a.arr[counter] << "\n";
        }
        else if (is.peek() == 10 || is.peek() == 13)
        {
            is.ignore(); //takes newline character off input stream
            return is;
        }
        counter++;
    }
    return is;
}

//MEMBER FUNCTIONS

//Default Constructor
MyInt::MyInt(int n)
{
    arr = 0;

    if(n < 1)
    {
        current = 0;
        max = 5;
    }
    else
    {
        current = Count(n);
        max = current + 5;
    }

    arr = new char[max];

    if(n > 0)
    {
        for(int i = current-1; i >= 0; i--)
        {
            arr[i] = static_cast<char> (n % 10) + '0';
            n = n/10;
        }
    }
}

//Other Constructor
MyInt::MyInt(const char given[])
{
    if(strlen(given) == 0)
    {
        current = 0;
        max = 5;
        arr = new char[max];
        return;
    }


    for(int i = 0; i < strlen(given); i++)
    {
        //ERROR CHECKING
        if (given[i] < 48 || given[i]> 57)
        {
            //if string is empty or contains any characters other than digits
            //('0' through '9'), set the object to represent the value 0
            current = 0;
            max = 5;
            arr = new char[max];
            return;
        }
    }

    current = static_cast<int> (strlen(given));
    max = current + 5;

    arr = new char[max];

    for (int j = 0; j < current; j++)
        arr[j] = given[j];
}

//Copy Constructor
MyInt::MyInt(const MyInt& i)
{
    //First, copy static variables
    max = i.max;
    current = i.current;

    //New dynamic array for new object's pointer
    arr = new char[max];

    //Copy dynamic data
    for(int j = 0; j < current; j++)
        arr[j] = i.arr[j];

}

//Destructor
MyInt::~MyInt()
{
    //Deallocates pointer
		delete [] arr;
    arr = 0;
}

//Assignment Operator
MyInt& MyInt::operator=(const MyInt & i)
{
    if (this != &i) //if they do not already equal each other
    {
        //delete any info currently attached
        delete [] arr;

        max = i.max;
        current = i.current;
        arr = new char[max];
        for(int j = 0; j < current; j++)
            arr[j] = i.arr[j];
    }

    return *this;
}

//Overload increment and decrement operators
MyInt& MyInt::operator++()    // prefix increment
{
    MyInt a(1);
    *this = *this + a;

    return *this;
}

MyInt MyInt::operator++(int)  // postfix increment
{
    MyInt a(1);
    MyInt temp = *this + a;

    return temp;
}



//Grow Func
void MyInt::Grow()
{
    max = current + 5;

    //make entirely new array to then transfer over data
    char* temp = new char[max];
    for (int i = 0; i < current; i++)
        temp[i] = arr[i];

    //remove old array and repurpose old pointer name to new array
    delete [] arr;
    arr = temp;
}

int MyInt::Count(int a) const
{
    //Function counts digits in an int and returns them
    //Assumes there is at least one digit
    unsigned int count = 0;
    do
    {
        a = a/10;
        count++;

    }while(a > 0);

    return count;
}
