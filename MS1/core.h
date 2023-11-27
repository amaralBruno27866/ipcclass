
// Copy the below commented "header" section to all your source code files!

/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 1
Full Name  : Bruno Amaral
Student ID#: 143766228
Email      : bamaral2@myseneca.ca
Section    : ZFF

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/


// ----------------------------------------------------------------------------
// (Do not copy the below)
// ----------------------------------------------------------------------------

// ############################################################################
//
//  Assignment:  1 
//  Milestone:   1
//  Description: Main tester
//
// +---------------------------------------------------------+
// | *** The contents of this file is NOT to be modified *** |    
// +---------------------------------------------------------+
//
//                         HOWEVER....
//
// In the development of your solution, you can...
// -----------------------------------------------
// - Comment the lines of code which call a function you have not yet developed
//   (See each tester function definition to see where you can do this)
// - Uncomment the lines of code previously commented to return the file to its
//   original state so you may fully test your solution.
// 
// ############################################################################

#ifndef CORE_H
#define CORE_H

void clearInputBuffer(void);
void suspend(void);
int inputInt(void);
int inputIntPositive(void);
int inputIntRange(int lowerLimit, int upperLimit);
char inputCharOption(const char* validChars);
void inputCString(char* str, int minLength, int maxLength);
void displayFormattedPhone(const char* phoneNumber);

#endif // CORE_H