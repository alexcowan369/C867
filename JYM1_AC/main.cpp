#include <iostream>
#include <string>
// Roster class in included via the roster header for use later in the file
#include "roster.h"
using namespace std;
// main function or entry point of the program
int main() {
// variable is created and initialized to 5, the variable with keep track of the 5 students used in the roster
   int numberofStudents = 5;
// below is the array of strings which contains the student information
// const is used to prevent the array form changing
   const string studentsInfo[5] =
   {
       "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
       "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
       "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
       "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
       "A5,Alexander,Cowan,joebob@wgu.edu,22,13,26,39,SOFTWARE",
   };
// Roster object is created from roster class
   Roster* roster = new Roster(numberofStudents);
   // The loop below iterates over the studentsInfo array from above
   for (int i = 0; i < numberofStudents; i++)
   {
       roster->parseNow(studentsInfo[i]);
       // This method from the roster class parses through the data into individual fields then creates a new
       // student object to add to the roster
   }
// Below are the print statements which are displayed in the terminal environment
   cout << "Printing Student Roster: " << endl;
   roster->printAll();
   cout << "---[Completed]---" << endl;
// checks the roster to print any invalid emails for data integrity purposes
   roster->printInvalidEmails();
   cout << "---[Completed]---" << endl;
  
   cout << "Displaying average days left in the course: " << endl;
   // iterating through the studentInfo array again
   for (int i = 0; i < numberofStudents; i++)
   // the function call below prints and calculates the number of days left in course
   {
       roster->printAverageDaysInCourse(roster->getStudent(i)->getStudentID());
   }
   cout << "---[Completed]---" << endl;
   // degree program is printed out for roster
   roster->printByDegreeProgram(DegreeProgram::SOFTWARE);
   cout << "---[Completed]---" << endl;
   // below removes the student via their ID number, in this case A3
   cout << "Removing student A3: " << endl;
   roster->remove("A3");
   cout << "---[Removed]---" << endl;
   // prints roster based off of the method used
   cout << "Printing Student Roster: " << endl;
   roster->printAll();
   cout << "---[Completed]---" << endl;
   // student object is removed from the roster
   cout << "Removing student A3: " << endl;
   roster->remove("A3");
   cout << "---[Completed]---" << endl;

   system("endloop");

   
}


