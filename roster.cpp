#include <iostream>
#include "roster.h"
using namespace std;

Roster::Roster()
{
   this->maximumSize = 0;
   this->lastIndex = -1;
   this->classRosterArray = nullptr;
}

Roster::Roster(int maximumSize)
{
   this->maximumSize = maximumSize;
   this->lastIndex = -1;
   this->classRosterArray = new Student * [maximumSize];
}

void Roster::parseNow(string row)
{  
   int checkArray[Student::tableValue];
   DegreeProgram degreeprogram;

   if (lastIndex < maximumSize)
   {
       lastIndex++;
   }
  
   this->classRosterArray[lastIndex] = new Student();

   //Comma used as deliminator for each parse
   //reading the student ID
   int long var1 = row.find(",");
   classRosterArray[lastIndex]->setID(row.substr(0, var1));

   //reading firstName
   int long var2 = var1 + 1;
   var1 = row.find(",", var2);
   classRosterArray[lastIndex]->setFirst(row.substr(var2, var1 - var2));

   //reading lastName
   var2 = var1 + 1;
   var1 = row.find(",", var2);
   classRosterArray[lastIndex]->setLast(row.substr(var2, var1 - var2));

   //reading emailAddress
   var2 = var1 + 1;
   var1 = row.find(",", var2);
   classRosterArray[lastIndex]->setEmail(row.substr(var2, var1 - var2));

   //reading age
   var2 = var1 + 1;
   var1 = row.find(",", var2);
   int x = stoi(row.substr(var2, var1 - var2));
   classRosterArray[lastIndex]->setAge(x);

   //reading daysInCourse1
   var2 = var1 + 1;
   var1 = row.find(",", var2);
   checkArray[0]= stoi(row.substr(var2, var1 - var2));

   //reading daysInCourse2
   var2 = var1 + 1;
   var1 = row.find(",", var2);
   checkArray[1] = stoi(row.substr(var2, var1 - var2));

   //read daysInCourse3
   var2 = var1 + 1;
   var1 = row.find(",", var2);
   checkArray[2] = stoi(row.substr(var2, var1 - var2));

   //set the days left in course
   classRosterArray[lastIndex]->setDaysToComplete(checkArray);

   //read degree program
   var2 = var1 + 1;
   if (row[var2] == 'S')
       {
           if (row[var2 + 1] == 'E') classRosterArray[lastIndex]->setDegreeProgram(SECURITY);
           else if (row[var2 + 1] == 'O') classRosterArray[lastIndex]->setDegreeProgram(SOFTWARE);
           else
           {
               cerr << "***INCORRECT DEGREE PROGRAM***" << endl;
               exit(-1);
           }
       }
       else if (row[var2] == 'N') classRosterArray[lastIndex]->setDegreeProgram(NETWORK);
       else
       {
           cerr << "***INCORRECT DEGREE PROGRAM***" << endl;
           exit(-1);
       }  
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogam)
{
   int arrayDaysToComplete[Student::tableValue];

   arrayDaysToComplete[0] = daysInCourse1;
   arrayDaysToComplete[1] = daysInCourse2;
   arrayDaysToComplete[2] = daysInCourse3;

   classRosterArray[lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, arrayDaysToComplete, degreeprogam);
}

Student* Roster::getStudent(int index)
{
   return classRosterArray[index];
}

void Roster::printAll()
{
   for (int i = 0; i <= this->lastIndex; i++) (this->classRosterArray)[i]->print();
}

bool Roster::remove(string studentID)
{
   bool found = false;
   for (int i = 0; i <= lastIndex; i++)
   {
       if (this->classRosterArray[i]->getStudentID() == studentID)
       {
           found = true;
           delete this->classRosterArray[i];
           this->classRosterArray[i] = this->classRosterArray[lastIndex];
           lastIndex--;
       }
   }
   if (!found)
   {
       cout << "Student with ID " << studentID << " is not found." << endl;
   }
   return found;
}

void Roster::printAverageDaysInCourse(string studentID)
{
   bool found = false;
   for (int i = 0; i <= lastIndex; i++)
   {
       if (this->classRosterArray[i]->getStudentID() == studentID)
       {
           found = true;
           int* printroster = classRosterArray[i]->getDaysToComplete();
           cout << "Average number of days left in class for " << studentID << " is " << (printroster[0] + printroster[1] + printroster[2]) / 3 << "\n";
       }
   }
   if (!found) cout << "Student not found!\n";
}

void Roster::printInvalidEmails()
{
   cout << "Displaying invalid email entries:\n";
   for (int i = 0; i < 5; i++)
   {
       string email = classRosterArray[i]->getEmailAddress();
       if ((email.find("@") == string::npos || email.find(".") == string::npos) || (email.find(" ") != string::npos))
           cout << email << endl;
   }
}

void Roster::printByDegreeProgram(DegreeProgram degreeprogram)
{
   cout << "Printing by degree " << DegreeTypes[degreeprogram] << endl;
   for (int i = 0; i <= lastIndex; i++) {
       if (this->classRosterArray[i]->getDegreeProgram() == degreeprogram) this->classRosterArray[i]->print();
   }
}

Roster::~Roster()
{
   for (int i = 0; i < 5; i++)
   {
       delete this->classRosterArray[i];
   }
   delete this;
}
