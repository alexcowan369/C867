// including the header file for the student class
#include "student.h"
#include <iostream>
#include <string>
#pragma once
// class of roster is created below
class Roster
{
    // denoted as public class, can be accessed from outside the class location
public:
    // integer member variable declared
   int lastIndex;
    // integer variable declared as value of 5
   int maximumSize = 5;
    // dynamically allocated array of pointers created below
   Student** classRosterArray;

   // constructor of the roster class will be called later when objects are created
   // methods are below, or functions of the class
   Roster();
   Roster(int maximumSize);
    // for parsing the row later
   void parseNow(string row);
    // takes nine arguments which are the values we want from each student
   void add(
       string studentID,
       string firstName,
       string lastName,
       string emailAddress,
       int age,
       int daysInCourse1,
       int daysInCourse2,
       int daysInCourse3,
       DegreeProgram degreeprogram
   );
    // function returns a pointer to the student object when called
   Student* getStudent(int index);
   // prints all student records in the roster
   void printAll();
   // removes a student record from the roster array based on studentID
   bool remove(string studentID);
   // print days in course for specific student via ID
   void printAverageDaysInCourse(string studentID);
   // print invalid emails in roster array
   void printInvalidEmails();
   // prints records of students who are enrolled in specific degree program
   void printByDegreeProgram(DegreeProgram degreeprogram);
   ~Roster();
};
