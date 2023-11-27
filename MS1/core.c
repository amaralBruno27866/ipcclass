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

#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_SIZE 20
#include "core.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

void clearInputBuffer(void)
{
    while (getchar() != '\n')
    {
        ; //Don't put any thing in this 
    }
}


void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}


int inputInt(void)
{
    int valueOfNumber;
    char character = 0;

    // Using Do-While Loop

    do {
        scanf("%d%c", &valueOfNumber, &character);

        if (character != '\n')
        {
            printf("Error! Input a whole number: ");
            clearInputBuffer();
        }
    } while (character != '\n');

    return valueOfNumber;
}


int inputIntPositive(void)
{
    int valueOfNumber;
    char character = 0;
    int keepLooping = 1;

    // Using Nested loop

    do {
        scanf("%d%c", &valueOfNumber, &character);

        if (valueOfNumber <= 0)
        {
            printf("ERROR! Value must be > 0: ");
        }
        else if (character != '\n')
        {
            printf("Error! Input a whole number: ");
            clearInputBuffer();
        }
        else
        {
            keepLooping = 0;
        }
    } while (keepLooping);

    return valueOfNumber;
}


int inputIntRange(int minRange, int maxRange)
{
    int valueOfNumber = minRange - 1;
    char character;

    do
    {
        scanf("%d%c", &valueOfNumber, &character);

        if (character != '\n')
        {
            printf("Error! Input a whole number: ");
            clearInputBuffer();
        }
        else if (valueOfNumber < minRange || valueOfNumber > maxRange)
        {
            printf("ERROR! Value must be between %d and %d inclusive: ", minRange, maxRange);

        }
    } while (valueOfNumber < minRange || valueOfNumber > maxRange);

    return valueOfNumber;
}


char inputCharOption(const char listChar[])
{
    int i;
    int z = 0;
    char inputValue;

    do {
        scanf(" %c", &inputValue);

        for (i = 0; listChar[i] != '\0'; i++)
        {
            if (inputValue == listChar[i])
            {
                z++;
            }
        }

        if (z == 0)
        {
            printf("ERROR: Character must be one of [%s]: ", listChar);
        }

    } while (z == 0);

    clearInputBuffer();

    return inputValue;

}


void inputCString(char* string, int minNoOfChar, int maxNoOfChar)
{
    int i;
    int z = 0;
    char inputValue[ARRAY_SIZE] = { 0 };

    do
    {
        z = 0;
        scanf(" %99[^\n]", inputValue);

        for (i = 0; inputValue[i] != '\0'; i++)
        {
            z++;
        }
        if (!(z <= maxNoOfChar && z >= minNoOfChar))
        {
            if (minNoOfChar == maxNoOfChar)
            {
                printf("ERROR: String length must be exactly %d chars: ", maxNoOfChar);
            }
            else if (minNoOfChar != maxNoOfChar)
            {
                if (z > maxNoOfChar)
                {
                    printf("ERROR: String length must be no more than %d chars: ", maxNoOfChar);
                }
                else if (z < minNoOfChar)
                {
                    printf("ERROR: String length must be between %d and %d chars: ", minNoOfChar, maxNoOfChar);
                }
            }
        }
    } while (!(z <= maxNoOfChar && z >= minNoOfChar));

    for (i = 0; inputValue[i] != '\0'; i++)
    {
        string[i] = inputValue[i];
    }
}


void displayFormattedPhone(const char* string)
{
    int keepLooping = 1;
    int i;

    if (string != NULL)
    {
        for (i = 0; string[i] && keepLooping; i++)
        {
            if (string[i] < 48 || string[i] > 57)
            {
                keepLooping = 0;
            }
        }
    }

    // Using If else to generate output 

    if (i == 10 && keepLooping == 1)
    {
        printf("(");

        for (i = 0; i < 3; i++)
        {
            printf("%c", string[i]);
        }
        printf(")");

        for (i = 3; i < 6; i++)
        {
            printf("%c", string[i]);
        }
        printf("-");

        for (i = 6; i < 10; i++)
        {
            printf("%c", string[i]);
        }
    }
    else
    {
        printf("(___)___-____");
    }
}
