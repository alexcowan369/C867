
// Libraries are imported below, iostream for input/output operations
// string library for manipulation of strings
// make sure the header file here is only included once to prevent compilation errors
// namespace std prevents having to write functions, variables, etc without the std:: prior to it
#include <iostream>
#include <string>
#pragma once
using namespace std;

// Enumerated data type DegreeProgram assigned/defined with SECURITY,NETWORK,SOFTWARE
// Note the data type has an integer associated with it hence the reasoning for enumerated data type
// Security = 0, Network = 1, Software = 2 for example
enum DegreeProgram {SECURITY,NETWORK,SOFTWARE};

// Below is a "static" array which does not allow it to be modified after being initialized
// Similar to a tuple in python where you do not want the values to change
static const string DegreeTypes[] = { "SECURITY", "NETWORK", "SOFTWARE" };
