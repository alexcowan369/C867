#include "student.h"
#include <string>
#include <iostream>
using namespace std;


Student::Student()
{
   this->studentID = "";
   this->firstName = "";
   this->lastName = "";
   this->emailAddress = "";
   this->age = 0;
   this->arrayDaysToComplete = new int[tableValue];
   for (int i = 0; i < tableValue; i++) this->arrayDaysToComplete[i] = 0;
   this->dgram = SOFTWARE;

}

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int arrayDaysToComplete[], DegreeProgram dgram)
{
   this->studentID = studentID;
   this->firstName = firstName;
   this->lastName = lastName;
   this->emailAddress = emailAddress;
   this->age = age;
   this->arrayDaysToComplete = new int[tableValue];
   for (int i = 0; i < tableValue; i++) this->arrayDaysToComplete[i] = arrayDaysToComplete[i];
   this->dgram = dgram;
}

//Getter functions
string Student::getStudentID()
{
   return studentID;
}

string Student::getFirstName()
{
   return firstName;
}

string Student::getLastName()
{
   return lastName;
}

string Student::getEmailAddress()
{
   return emailAddress;
}

int Student::getAge()
{
   return age;
}

int* Student::getDaysToComplete()
{
   return arrayDaysToComplete;           //pointer to  the establsihed array
}

DegreeProgram Student::getDegreeProgram()
{
   return dgram;
}


//Setter functions

void Student::setID(string studentID)
{
   this->studentID = studentID;
}

void Student::setFirst(string firstName)
{
   this->firstName = firstName;
}

void Student::setLast(string lastName)
{
   this->lastName = lastName;
}

void Student::setEmail(string emailAddress)
{
   this->emailAddress = emailAddress;
}

void Student::setAge(int age)
{
   this->age = age;
}

void Student::setDaysToComplete(int arrayDaysToComplete[])
{
   for (int i = 0; i < tableValue; i++)
   {
       this->arrayDaysToComplete[i] = arrayDaysToComplete[i];
   }
}

void Student::setDegreeProgram(DegreeProgram dgram)
{
   this->dgram = dgram;
}

void Student::print()
{
   cout << getStudentID() << '\t' << getFirstName() << '\t' << getLastName() << '\t' << getAge() << '\t';
   int * arrayDaysToComplete = getDaysToComplete();
   cout << '\t' << "daysInCourse: " << "{" << arrayDaysToComplete[0] << ", " << arrayDaysToComplete[1] << ", " << arrayDaysToComplete[2] << "}" << '\t';
   cout << "Degree Program: " << DegreeTypes[getDegreeProgram()] << endl;
}

//Destructor
Student::~Student()
{
   if (arrayDaysToComplete != nullptr)
   {
       delete[] arrayDaysToComplete;
       arrayDaysToComplete = nullptr;
   }
}
