#include <iostream>
#include <string>
#include "roster.h"
using namespace std;

int main() {

   int numberofStudents = 5;

   const string studentsInfo[5] =
   {
       "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
       "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
       "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
       "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
       "A5,Alexander,Cowan,acowa37@wgu.edu,22,13,26,39,SOFTWARE",
   };

   Roster* roster = new Roster(numberofStudents);
   for (int i = 0; i < numberofStudents; i++)
   {
       roster->parseNow(studentsInfo[i]);
   }

   cout << "Printing Student Roster: " << endl;
   roster->printAll();
   cout << "---[Completed]---" << endl;

   roster->printInvalidEmails();
   cout << "---[Completed]---" << endl;
  
   cout << "Displaying average days left in the course: " << endl;
   for (int i = 0; i < numberofStudents; i++) {
       roster->printAverageDaysInCourse(roster->getStudent(i)->getStudentID());
   }
   cout << "---[Completed]---" << endl;

   roster->printByDegreeProgram(DegreeProgram::SOFTWARE);
   cout << "---[Completed]---" << endl;
  
   cout << "Removing student A3: " << endl;
   roster->remove("A3");
   cout << "---[Removed]---" << endl;

   cout << "Printing Student Roster: " << endl;
   roster->printAll();
   cout << "---[Completed]---" << endl;

   cout << "Removing student A3: " << endl;
   roster->remove("A3");
   cout << "---[Completed]---" << endl;

   system("endloop");

   
}


