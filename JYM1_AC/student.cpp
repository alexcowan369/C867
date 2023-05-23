#include "student.h"
#include <string>
#include <iostream>
using namespace std;

// Constructor of the student class
Student::Student()
{
    // setting up the pointer for use later in the program
    // "this" will be the pointer used
    // assigning empty strings to the proper
   this->studentID = "";
   this->firstName = "";
   this->lastName = "";
   this->emailAddress = "";
   this->age = 0;
   this->arrayDaysToComplete = new int[tableValue];
   for (int i = 0; i < tableValue; i++) this->arrayDaysToComplete[i] = 0;
   this->dgram = SOFTWARE;

}
// Constructor defined and showing the parameters it will take
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int arrayDaysToComplete[], DegreeProgram dgram)
{
    // used to initialize a new student object with values from below
   this->studentID = studentID;
   this->firstName = firstName;
   this->lastName = lastName;
   this->emailAddress = emailAddress;
   this->age = age;
   this->arrayDaysToComplete = new int[tableValue];
   for (int i = 0; i < tableValue; i++) this->arrayDaysToComplete[i] = arrayDaysToComplete[i];
   this->dgram = dgram;
}

// Getter functions, used to access private members or methods of the class
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
// this will return a pointer to the arrayDaysToComplete
// allows access of arrayDaysToComplete from outside the "Student" class
int* Student::getDaysToComplete()
{
   return arrayDaysToComplete;
}

DegreeProgram Student::getDegreeProgram()
{
   return dgram;
}


// Setter functions, these allow me to change the values of the private methods

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
// function below prints the student ID, name, age, days to complete courses, and the degree program
// it uses a tab seperated format noted by '\t'
void Student::print()
{
   cout << getStudentID() << '\t' << getFirstName() << '\t' << getLastName() << '\t' << getAge() << '\t';
   int * arrayDaysToComplete = getDaysToComplete();
   cout << '\t' << "daysInCourse: " << "{" << arrayDaysToComplete[0] << ", " << arrayDaysToComplete[1] << ", " << arrayDaysToComplete[2] << "}" << '\t';
   cout << "Degree Program: " << DegreeTypes[getDegreeProgram()] << endl;
}

// Destructor to clear up used memory
Student::~Student()
{
   if (arrayDaysToComplete != nullptr)
   {
       delete[] arrayDaysToComplete;
       arrayDaysToComplete = nullptr;
   }
}
