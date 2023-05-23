#include <iostream>
// connecting/importing the roster.h class for use later
#include "roster.h"
using namespace std;

// Below is the default constructor which initializes as empty "Roster"
// with no students, lastIndex is set to -1 to indicate no students have been added yet
Roster::Roster()
{
   this->maximumSize = 0;
   this->lastIndex = -1;
   this->classRosterArray = nullptr;
}
// below is another constructor that can hold the maximum amount of students
Roster::Roster(int maximumSize)
{
   this->maximumSize = maximumSize;
   this->lastIndex = -1;
   this->classRosterArray = new Student * [maximumSize];
}
// below parses the strings to find the requested data
// note there is a new student object created
// class Roster with parseNow function added to the class for functionality
void Roster::parseNow(string row)
// New array named checkArray defined, note the nested class
{  
   int checkArray[Student::tableValue];
   //Variable degreeprogram defined of the type DegreeProgram
   DegreeProgram degreeprogram;
   // Checking below to see if "lastIndex" is less than "maximumSize"
   if (lastIndex < maximumSize)
   {
       lastIndex++;
   }
   // new "Student" object is allocated
   // pointer is assigned to lastIndex
   // New student is added to the roster at the next index
   this->classRosterArray[lastIndex] = new Student();

   // Comma used as deliminator for each parse
   // allows for strings to be read in an easy fashion
   // reading the student ID
   int long var1 = row.find(",");
   // setId method called on the student object
   classRosterArray[lastIndex]->setID(row.substr(0, var1));

   // reading the firstName, similar pattern to above but we are looking
   // for the first name via the setFirst method
   // setting the var2 to be one position after var1 which identifies the name
   int long var2 = var1 + 1;
   // calling the find function on string "row"
   var1 = row.find(",", var2);
   // lastIndex element of classRosterArray is accessed
   // substring (name) is then returned from the instructed location
   classRosterArray[lastIndex]->setFirst(row.substr(var2, var1 - var2));

   // reading the lastName from the row, similar pattern
   var2 = var1 + 1;
   var1 = row.find(",", var2);
   classRosterArray[lastIndex]->setLast(row.substr(var2, var1 - var2));

   // reading the emailAddress from the row
   var2 = var1 + 1;
   var1 = row.find(",", var2);
   classRosterArray[lastIndex]->setEmail(row.substr(var2, var1 - var2));

   //reading the age from the row
   var2 = var1 + 1;
   var1 = row.find(",", var2);
   int x = stoi(row.substr(var2, var1 - var2));
   classRosterArray[lastIndex]->setAge(x);

   // reading the daysInCourse1 from the row
   var2 = var1 + 1;
   var1 = row.find(",", var2);
   checkArray[0]= stoi(row.substr(var2, var1 - var2));

   // reading the daysInCourse2 from the row
   var2 = var1 + 1;
   var1 = row.find(",", var2);
   checkArray[1] = stoi(row.substr(var2, var1 - var2));

   // reading the daysInCourse3 from the row
   var2 = var1 + 1;
   var1 = row.find(",", var2);
   checkArray[2] = stoi(row.substr(var2, var1 - var2));

   // set the days left in course
   classRosterArray[lastIndex]->setDaysToComplete(checkArray);

   // read degree program logic
   var2 = var1 + 1;
   // if string in row is equal to S the statement will be executed
   if (row[var2] == 'S')
        // checking to see if the string in row is equal to E, if not goes to else if
       {
           if (row[var2 + 1] == 'E') classRosterArray[lastIndex]->setDegreeProgram(SECURITY);
           else if (row[var2 + 1] == 'O') classRosterArray[lastIndex]->setDegreeProgram(SOFTWARE);
           else
           {
               cerr << "***INCORRECT DEGREE PROGRAM***" << endl;
               exit(-1);
           }
       } // follow the logic down if character is not equal to S, now checking for N
         // this applies to the logic similar above as well
         // if the N is satisfied Network is set as the degree program
       else if (row[var2] == 'N') classRosterArray[lastIndex]->setDegreeProgram(NETWORK);
       else
       // Simple print statement if conditions are not met above
       {
           cerr << "***INCORRECT DEGREE PROGRAM***" << endl;
           exit(-1);
       }  
}
// New class formed add function added with parameters to be passed into it
// No value to be returned by function noted using void
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogam)
// Similar to what was done in previous classes
// array of integers is declared, using a Student class with tableValue member
// Note the constant static integer of 3 is passed via tableValue to set array size
{
   int arrayDaysToComplete[Student::tableValue];
    // Values daysInCourseX assigned to elements of array
   arrayDaysToComplete[0] = daysInCourse1;
   arrayDaysToComplete[1] = daysInCourse2;
   arrayDaysToComplete[2] = daysInCourse3;
    // New instance of Student created, all function parameters as passed into it
   classRosterArray[lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, arrayDaysToComplete, degreeprogam);
}
// Student* points to an instance of the Student class
// function as member of class, index_number noted as integer
Student* Roster::getStudent(int index_number)
{
   return classRosterArray[index_number];
}

void Roster::printAll()
// for loop iterating over the array from first index (0) to last index
// note "this->" pointer is used to access the lastIndex member of roster object
{
   for (int i = 0; i <= this->lastIndex; i++) (this->classRosterArray)[i]->print();
}
// Students are removed via their studentID using the remove function in the Roster class's
bool Roster::remove(string studentID)
// found variable is set to a default of false
{
   bool found = false;
   // Iterates through the indexes of class roster array
   for (int i = 0; i <= lastIndex; i++)
   {
       // Looking to see if the student id matches the student id parameter
       // this would indicate a match
       if (this->classRosterArray[i]->getStudentID() == studentID)
       {
           found = true; // boolean variable found is then changed to true if located
           delete this->classRosterArray[i]; // student deleted from memory
           // student moved to specific index
           this->classRosterArray[i] = this->classRosterArray[lastIndex];
           lastIndex--;
       }
   }
   // this is the logic if a student is not found with given ID
   // prints or "cout" the message below
   if (!found)
   {
       cout << "Student with ID " << studentID << " is not found." << endl;
   }
   // below should print true or false dependent on the outcome
   return found;
}
// printAverageDaysInCourse method of the roster class is below
// printing the days left for a specific student via the student ID
// the one parameter is studentID
void Roster::printAverageDaysInCourse(string studentID)
// similar to above we are setting the found varible to false
{
   bool found = false;
   // iterate through each student from index location 0
   for (int i = 0; i <= lastIndex; i++)
   {
       // checking for a match of student id
       if (this->classRosterArray[i]->getStudentID() == studentID)
       {
           found = true;
           // pointer to classRosterArray stored in the printroster variable
           int* printroster = classRosterArray[i]->getDaysToComplete();
           cout << "Average number of days left in class for " << studentID << " is " << (printroster[0] + printroster[1] + printroster[2]) / 3 << "\n";
       }
   }
   // similar to above if found is false statement printed out below
   if (!found) cout << "Student not found!\n";
}
// function for invalid emails applied to Roster class
void Roster::printInvalidEmails()
{
   cout << "Displaying invalid email entries:\n";
   // iterating through the emails 5 times
   for (int i = 0; i < 5; i++)
   // email variable stores the email address of current student
   {
       string email = classRosterArray[i]->getEmailAddress();
       // if statement looking for the @, ., or space character to find email address
       // if not found npos is returned
       if ((email.find("@") == string::npos || email.find(".") == string::npos) || (email.find(" ") != string::npos))
           cout << email << endl;
   }
}
// printByDegreeProgram function part of the Roster class with parameter degreeprogram
void Roster::printByDegreeProgram(DegreeProgram degreeprogram)
{
   cout << "Printing by degree " << DegreeTypes[degreeprogram] << endl;
   // iterating through to find index
   for (int i = 0; i <= lastIndex; i++) {
       // calls print function of array when student matches the parameter
       if (this->classRosterArray[i]->getDegreeProgram() == degreeprogram) this->classRosterArray[i]->print();
   }
}
// destructor for the roster class
// used to release resources that the object has acquired
// via pointers allocating memory, freeing up memory space
Roster::~Roster()
{
    // iterate through
    for (int i = 0; i <= lastIndex; i++)
    {
        // delete at the i positions
        delete classRosterArray[i];
    }
    // deleting the array
    delete[] classRosterArray;
}

