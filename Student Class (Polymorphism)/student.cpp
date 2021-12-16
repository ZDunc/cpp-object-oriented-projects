//Zach Duncan

#include "student.h"
#include <iostream>
#include <cstring>

using namespace std;

//MEMBER FUNCTIONS FOR BASE STUDENT CLASS

//Default Constructor
Student::Student()
{
    fName[0] = 0;
    lName[0] = 0;
    course[0] = 0;
}

//Constructor with parameters
Student::Student(const char* f, const char* l, const char* c)
{
    strcpy(fName, f);
    strcpy(lName, l);
    strcpy(course, c);
}


//MEMBER FUNCTIONS FOR DERIVED BIOSTUDENT CLASS

//Default
BioStudent::BioStudent()
{
    lab = 0;
    test1 = 0;
    test2 = 0;
    test3 = 0;
    final = 0;
}

//Constructor with parameters
BioStudent::BioStudent(const char* f, const char* l, const char* c,
                       int lb, int t1, int t2, int t3, int fl)
        : Student(f,l,c)
{
    lab = lb;
    test1 = t1;
    test2 = t2;
    test3 = t3;
    final = fl;
}

//BioStudent Avg
double BioStudent::FinalAverage()
{
    double avg;
    avg = ( ((lab*30)+(test1*15)+(test2*15)+(test3*15)+(final*25))/100.0 );

    return avg;
}

//MEMBER FUNCTIONS FOR DERIVED THEATERSTUDENT CLASS

//Default
TheaterStudent::TheaterStudent()
{
    part = 0;
    midterm = 0;
    final = 0;
}

//Constructor with parameters
TheaterStudent::TheaterStudent(const char* f, const char* l, const char* c,
                               int p, int m, int fl)
        : Student(f,l,c)
{
    part = p;
    midterm = m;
    final = fl;
}

//TheaterStudent Avg
double TheaterStudent::FinalAverage()
{
    double avg;
    avg = ( ((part*40)+(midterm*25)+(final*35))/100.0 );

    return avg;
}

//MEMBER FUNCTIONS FOR DERIVED COMPSCISTUDENT CLASS

//Default
CompSciStudent::CompSciStudent()
{
    programAverage = 0;
    test1 = 0;
    test2 = 0;
    final = 0;
}

//Constructor with parameters
CompSciStudent::CompSciStudent(const char* f, const char* l, const char* c,
                               int p1, int p2, int p3, int p4,
                               int p5, int p6, int t1, int t2,
                               int fl)
        : Student(f,l,c)
{
    programAverage = ((p1+p2+p3+p4+p5+p6)/6.0);
    test1 = t1;
    test2 = t2;
    final = fl;
}

//CompSciStudent Avg
double CompSciStudent::FinalAverage()
{
    double avg;
    avg = ( ((programAverage*30)+(test1*20)+(test2*20)+(final*30))/100.0 );

    return avg;
}
