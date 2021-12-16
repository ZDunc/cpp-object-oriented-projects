#include <iostream>
using namespace std;

class MyInt
{
    //Overload arithmetic operations
    friend MyInt operator+(const MyInt& a, const MyInt& b);

    //Overload boolean comparison operators
    friend bool operator<(const MyInt& a, const MyInt& b);
    friend bool operator>(const MyInt& a, const MyInt& b);
    friend bool operator<=(const MyInt& a, const MyInt& b);
    friend bool operator>=(const MyInt& a, const MyInt& b);
    friend bool operator==(const MyInt& a, const MyInt& b);
    friend bool operator!=(const MyInt& a, const MyInt& b);

    //Overload Input and Output Streams
    friend ostream& operator<<(ostream& , const MyInt& );
    friend istream& operator>>(istream& , MyInt& );

public:
    MyInt(int n = 0); //Default Constructor
    MyInt(const char given[]); //Other Constructor

    MyInt(const MyInt& i); //Copy Constructor
    ~MyInt(); //Destructor

    MyInt& operator=(const MyInt & i); //Assignment Operator

    //Overload increment and decrement operators
    MyInt& operator++();    // prefix increment
    MyInt operator++(int);  // postfix increment

    void Grow();
    int Count(int) const;

private:

    //CREATE DYNAMIC ARRAY
    //bound by values allowed in unsigned int variable
    char* arr;

    unsigned int current;      //current size of array
    unsigned int max;          //limits max array size to 5 greater than current
};
