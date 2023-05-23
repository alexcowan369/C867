#pragma once
#include "degree.h"
#include <string>
#include <iostream>
using namespace std;

// class of student defined
class Student
{
    // public for usage across the program
public:
    // constant integer value of 3 assigned to tableValue
   const static int tableValue = 3;
    // following are private and can only be accessed from the methods below
private:
    // methods below which hold data for student objects
   string studentID;
   string firstName;
   string lastName;
   string emailAddress;
   int age;
   int * arrayDaysToComplete;
   DegreeProgram dgram;
  
public:
   // default constructor
   Student();
  
   // full constructor, matching the name of the class
   // parameters below for what the constructor will take 
   // allows us to pass variables into the object when instantiated
   Student(
       string studentID,
       string firstName,
       string lastName,
       string emailAddress,
       int age,
       int arrayDaysToComplete[],
       DegreeProgram dgram
   );

   // getter for the instances, these return the value of corresponding method below
   string getStudentID();
   string getFirstName();
   string getLastName();
   string getEmailAddress();
   int getAge();
   int* getDaysToComplete();
   DegreeProgram getDegreeProgram();

   // setters, these take a parameter and set the value to the parameter inputted
   void setID(string studentID);
   void setFirst(string firstName);
   void setLast(string lastName);
   void setEmail(string emailAddress);
   void setAge(int age);
   void setDaysToComplete(int arrayDaysToComplete[]);
   void setDegreeProgram(DegreeProgram dgram);
   void print();

   // destructor to clean up and resources used to free space
   ~Student();

};
