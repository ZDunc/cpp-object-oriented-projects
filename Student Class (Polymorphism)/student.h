//Zach Duncan

#ifndef _STUDENT_H
#define _STUDENT_H

//using namespace std;

//Base Class
class Student
{
public:
    Student();
    Student(const char* f, const char* l, const char* c);

    virtual double FinalAverage()=0;

    //ACCESSOR FUNCTIONS
    const char* GetfName() const {return fName;}
    const char* GetlName() const {return lName;}
    const char* Getcourse() const {return course;}
    virtual double GetFinalTest()=0;

protected:
    char fName[20];
    char lName[20];
    char course[17];
};

class BioStudent : public Student
{
public:
    BioStudent();
    BioStudent(const char* f, const char* l, const char* c,
               int lb, int t1, int t2, int t3, int fl);
    double FinalAverage();

    double GetFinalTest() {return final;}

private:
    int lab;
    int test1;
    int test2;
    int test3;
    int final;
};

class TheaterStudent : public Student
{
public:
    TheaterStudent();
    TheaterStudent(const char* f, const char* l, const char* c,
                   int p, int m, int fl);
    double FinalAverage();

    double GetFinalTest() {return final;}

private:
    int part;
    int midterm;
    int final;
};

class CompSciStudent : public Student
{
public:
    CompSciStudent();
    CompSciStudent(const char* f, const char* l, const char* c,
                   int p1, int p2, int p3, int p4, int p5,
                   int p6, int t1, int t2, int fl);
    double FinalAverage();

    double GetFinalTest() {return final;}

private:
    double programAverage;
    int test1;
    int test2;
    int final;
};

#endif //_STUDENT_H
