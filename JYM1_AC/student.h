#pragma once
#include "degree.h"
#include <string>
#include <iostream>
using namespace std;

//Don't forget class definitions here
class Student
{
public:
   const static int tableValue = 3;

private:
   string studentID;
   string firstName;
   string lastName;
   string emailAddress;
   int age;
   int * arrayDaysToComplete;
   DegreeProgram dgram;
  
public:
   //default constructor
   Student();
  
   //full constructor
   Student(
       string studentID,
       string firstName,
       string lastName,
       string emailAddress,
       int age,
       int arrayDaysToComplete[],
       DegreeProgram dgram
   );

   //getter for the instances
   string getStudentID();
   string getFirstName();
   string getLastName();
   string getEmailAddress();
   int getAge();
   int* getDaysToComplete();
   DegreeProgram getDegreeProgram();

   //setters
   void setID(string studentID);
   void setFirst(string firstName);
   void setLast(string lastName);
   void setEmail(string emailAddress);
   void setAge(int age);
   void setDaysToComplete(int arrayDaysToComplete[]);
   void setDegreeProgram(DegreeProgram dgram);
   void print();

   //destructor
   ~Student();

};
