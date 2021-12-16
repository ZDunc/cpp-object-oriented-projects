//Zach Duncan

#include "studentlist.h"
#include "student.h"
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    //Variable declarations
    StudentList sList;
    char choice;

    sList.Menu();      //Call list menu

    do
    {
        cout << "> ";  //suggesting user input for menu choice
        cin >> choice;
        cin.ignore();  //ignore newline from input stream

        choice = (char) toupper(choice);

        switch (choice)
        {
            case 'I':
            {
                char filename[30];

                cout << "Enter filename: ";
                cin >> filename;

                if (! sList.ImportFile(filename))
                {
                    cout << "Invalid file. No data imported\n";
                    break;
                }
                else
                    break;
            }
            case 'S':
            {
                sList.ShowList();
                break;
            }
            case 'E':
            {
                char filename[30];

                cout << "Enter filename: ";
                cin >> filename;

                if (! sList.CreateReportFile(filename))
                {
                    cout << "Failure. Output file cannot"
                            " be opened.\n";
                    break;
                }
                else
                    break;
            }
            case 'M':
            {
                sList.Menu();
                break;
            }
            case 'Q':
                break;
            default:
            {
                cout << "Invalid option. Try again.\n";
                break;
            }

        }//end of switch statement

    }while(choice != 'Q'); //end of do/while loop

    return 0;
}
