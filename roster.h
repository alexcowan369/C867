
#include "student.h"
#include <iostream>
#include <string>
#pragma once

class Roster
{
public:  
   int lastIndex;
   int maximumSize = 5;
   Student** classRosterArray; //array of pointers

   //constructor
   Roster();
   Roster(int maximumSize);

   void parseNow(string row);
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

   Student* getStudent(int index);
   void printAll();
   bool remove(string studentID);
   void printAverageDaysInCourse(string studentID);
   void printInvalidEmails();
   void printByDegreeProgram(DegreeProgram degreeprogram);
   ~Roster();
};
