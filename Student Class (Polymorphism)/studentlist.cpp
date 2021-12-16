//Zach Duncan

#include "studentlist.h"
#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>

using namespace std;

//Constructor
StudentList::StudentList()
{
    current = 0;
    list = 0; //list of student pointers to be initialized
              //when first Student is entered
}

//Destructor
StudentList::~StudentList()
{
    if (current > 0)
        delete [] list;
}

bool StudentList::ImportFile(const char* filename)
{
    ifstream in1;
    in1.open(filename);

    if (in1) //if file exists
    {
        int oldCurrent = current;
        int total;         //ttl num of students as stated in first line

        in1 >> total;
        Grow(total);       //max capacity of list is now old max +
                           //num of students in input file
        in1.ignore();      //ignores newline

        //FOR LOOP - goes through each student and adds to list
        for (int i = oldCurrent; i < current; i++)
        {
            //temp char arrays
            char temp1[20], temp2[20], temp3[17];

            //FIRST, READ IN NAME
            in1.getline(temp1, 20, ',');
            in1.ignore();                        //ignore space

            //READ LAST NAME until newline
            in1.getline(temp2, 20);

            //PEEK TO SEE STUDENT'S COURSE
            char temp;
            temp = (char) in1.peek();
            temp = (char) toupper(temp);

            //READ IN COURSE
            in1 >> temp3;
            if ( strcmp(temp3, "Computer") == 0)
            {
                strcat(temp3, " Science");
                in1.ignore(8); //throw away " Science" from stream
            }
            in1.ignore(); //ignore space after course

            if(temp == 'B') //Reading input for biology student
            {
                int lb, t1, t2, t3, fl;
                in1 >> lb;
                in1.ignore();
                in1 >> t1;
                in1.ignore();
                in1 >> t2;
                in1.ignore();
                in1 >> t3;
                in1.ignore();
                in1 >> fl;
                in1.ignore();

                list[i] = new BioStudent(temp2, temp1, temp3, lb, t1, t2, t3, fl);
            }
            else if(temp == 'T') //Reading input for theater student
            {
                int p, m, fl;
                in1 >> p;
                in1.ignore();
                in1 >> m;
                in1.ignore();
                in1 >> fl;
                in1.ignore();

                list[i] = new TheaterStudent(temp2, temp1, temp3, p, m, fl);
            }
            else if(temp == 'C') //Reading input for compsci student
            {
                int p1, p2, p3, p4, p5, p6;
                int t1, t2, fl;
                in1 >> p1;
                in1.ignore();
                in1 >> p2;
                in1.ignore();
                in1 >> p3;
                in1.ignore();
                in1 >> p4;
                in1.ignore();
                in1 >> p5;
                in1.ignore();
                in1 >> p6;
                in1.ignore();

                in1 >> t1;
                in1.ignore();
                in1 >> t2;
                in1.ignore();
                in1 >> fl;
                in1.ignore();

                list[i] = new CompSciStudent(temp2, temp1, temp3, p1, p2, p3, p4, p5, p6, t1, t2, fl);
            }
            else
                return false;
        }//END OF FOR LOOP

        in1.close();
        return true;
    }
    else
        return false;
}

bool StudentList::CreateReportFile(const char* filename)
{
    ofstream of1;
    of1.open(filename);

    if (of1)
    {
        of1 << "Student Grade Summary\n"
               "---------------------\n\n"
               "BIOLOGY CLASS\n\n"
               "Student                                   Final Final   Letter\n"
               "Name                                      Exam  Avg     Grade\n"
               "----------------------------------------------------------------------\n";

        //Count variables
        int countA = 0, countB = 0, countC = 0, countD = 0, countF = 0;

        //Go through studentlist array and print all bio students
        for (int i = 0; i < current; i++)
        {
            if( strcmp((list[i]->Getcourse()), "Biology") == 0)
            {
                of1.setf(ios::left);
                of1 << list[i]->GetfName() << ' ';
                of1.width (40 - strlen( list[i]->GetfName() ));
                of1 << list[i]->GetlName() << ' ';
                of1.width(6);
                of1 << list[i]->GetFinalTest();
                int oldprecision = (int) of1.precision();
                of1 << fixed << showpoint << setprecision(2);
                of1.width(8);
                of1 << list[i]->FinalAverage();
                of1.precision(oldprecision);
                of1.unsetf(ios::fixed);                           //UNSET FLAGS
                of1.unsetf(ios::showpoint);
                of1.unsetf(ios::left);

                //SWITCH STATEMENT FOR LETTER GRADES
                switch( (int) list[i]->FinalAverage()/10)
                {
                    case 10:
                    case 9:
                        of1 << "A\n";
                        countA++;
                        break;
                    case 8:
                        of1 << "B\n";
                        countB++;
                        break;
                    case 7:
                        of1 << "C\n";
                        countC++;
                        break;
                    case 6:
                        of1 << "D\n";
                        countD++;
                        break;
                    default:
                        of1 << "F\n";
                        countF++;
                        break;
                }//end of switch
            }//end of if statement
        }//end of for loop

        of1 << "\n\n";
        of1 << "THEATER CLASS\n\n"
               "Student                                   Final Final   Letter\n"
               "Name                                      Exam  Avg     Grade\n"
               "----------------------------------------------------------------------\n";

        //Go through studentlist array and print all theater students
        for (int j = 0; j < current; j++)
        {
            if( strcmp((list[j]->Getcourse()), "Theater") == 0)
            {
                of1.setf(ios::left);
                of1 << list[j]->GetfName() << ' ';
                of1.width (40 - strlen( list[j]->GetfName() ));
                of1 << list[j]->GetlName() << ' ';
                of1.width(6);
                of1 << list[j]->GetFinalTest();
                int oldprecision = (int) of1.precision();
                of1 << fixed << showpoint << setprecision(2);
                of1.width(8);
                of1 << list[j]->FinalAverage();
                of1.precision(oldprecision);
                of1.unsetf(ios::fixed);                           //UNSET FLAGS
                of1.unsetf(ios::showpoint);
                of1.unsetf(ios::left);

                //SWITCH STATEMENT FOR LETTER GRADES
                switch( (int) list[j]->FinalAverage()/10)
                {
                    case 10:
                    case 9:
                        of1 << "A\n";
                        countA++;
                        break;
                    case 8:
                        of1 << "B\n";
                        countB++;
                        break;
                    case 7:
                        of1 << "C\n";
                        countC++;
                        break;
                    case 6:
                        of1 << "D\n";
                        countD++;
                        break;
                    default:
                        of1 << "F\n";
                        countF++;
                        break;
                }//end of switch
            }//end of if statement
        }//end of for loop

        of1 << "\n\n";
        of1 << "COMPSCI CLASS\n\n"
               "Student                                   Final Final   Letter\n"
               "Name                                      Exam  Avg     Grade\n"
               "----------------------------------------------------------------------\n";

        //Go through studentlist array and print all compsci students
        for (int k = 0; k < current; k++)
        {
            if( strcmp((list[k]->Getcourse()), "Computer Science") == 0)
            {
                of1.setf(ios::left);
                of1 << list[k]->GetfName() << ' ';
                of1.width (40 - strlen( list[k]->GetfName() ));
                of1 << list[k]->GetlName() << ' ';
                of1.width(6);
                of1 << list[k]->GetFinalTest();
                int oldprecision = (int) of1.precision();
                of1 << fixed << showpoint << setprecision(2);
                of1.width(8);
                of1 << list[k]->FinalAverage();
                of1.precision(oldprecision);
                of1.unsetf(ios::fixed);                           //UNSET FLAGS
                of1.unsetf(ios::showpoint);
                of1.unsetf(ios::left);

                //SWITCH STATEMENT FOR LETTER GRADES
                switch( (int) list[k]->FinalAverage()/10)
                {
                    case 10:
                    case 9:
                        of1 << "A\n";
                        countA++;
                        break;
                    case 8:
                        of1 << "B\n";
                        countB++;
                        break;
                    case 7:
                        of1 << "C\n";
                        countC++;
                        break;
                    case 6:
                        of1 << "D\n";
                        countD++;
                        break;
                    default:
                        of1 << "F\n";
                        countF++;
                        break;
                }//end of switch
            }//end of if statement
        }//end of foor loop

        of1 << "\n\nOVERALL GRADE DISTRIBUTION\n\n";
        of1 << "A:\t" << countA << "\n";
        of1 << "B:\t" << countB << "\n";
        of1 << "C:\t" << countC << "\n";
        of1 << "D:\t" << countD << "\n";
        of1 << "F:\t" << countF;

        of1.close();

	return true;
    }
    else
        return false;
}

//Prints out basic data list
void StudentList::ShowList() const
{
    cout << "Last                            First                           Course\n\n";

    if (current > 0)
    {
        cout.setf(ios::left);
        for (int i = 0; i < current; i++)
        {
            cout.width(20);
            cout << list[i]->GetlName() << "\t\t";
            cout.width(20);
            cout << list[i]->GetfName() << "\t\t";
            cout.width(20);
            cout << list[i]->Getcourse() << '\n';
        }
        cout.unsetf(ios::left);
    }
}

//Print menu
void StudentList::Menu() const
{
    cout << "*** Student List menu ***\n"
            "\n"
            "        I       Import students from a file\n"
            "        S       Show student list (brief)\n"
            "        E       Export a grade report (to file)\n"
            "        M       Show this Menu\n"
            "        Q       Quit Program\n";
}

//Grows list size to accommodate for input needs
void StudentList::Grow(int n)
{
    if (current == 0) //list first initialized when growing from 0
    {
        list = new Student*[n];
        current = n;
    }
    else if (current > 0)
    {
        Student ** newList = new Student*[current + n];

        for (int i = 0; i < current; i++)
            newList[i] = list[i];

        delete[] list;
        list = newList;

        current = current + n;
    }
}
