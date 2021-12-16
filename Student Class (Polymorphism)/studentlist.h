#ifndef AS6_STUDENTLIST_H
#define AS6_STUDENTLIST_H

#include "student.h"

class StudentList
{
public:
    StudentList();		// starts out empty
    ~StudentList();		// cleanup (destructor)

    bool ImportFile(const char* filename);
    bool CreateReportFile(const char* filename);
    void ShowList() const;	// print basic list data
    void Menu() const;           // prints menu

private:
    Student ** list;              // pointer to pointer
                                  //For dynamic allocation of list
                                  //of Student pointers
    int current;			// current num of entries
    void Grow(int n = 1);	// will grow maximum size when appropriate
};

#endif //AS6_STUDENTLIST_H
