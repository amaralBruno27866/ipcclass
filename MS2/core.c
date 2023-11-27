/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 2
Full Name  : Bruno Amaral
Student ID#: 143766228
Email      : bamaral2@myseneca.ca
Section    : ZFF

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_SIZE 20
#include "core.h"
#include "clinic.h"
#include <stdio.h>
#include <string.h>

//
// Copy your work done from Milestone #1 (core.c) into this file
// - Organize your functions in the same order as they are listed in the core.h file
// - Also copy the commented "sections" to help with finding functions quickly!
//

// As demonstrated in the course notes: 
// https://intro2c.sdds.ca/D-Modularity/input-functions#clearing-the-buffer 
// Clear the standard input buffer 
void clearInputBuffer(void) {
	// Discard all remaining char's from the standard input buffer:
	while (getchar() != '\n') {
		; // do nothing! 
	}
}

// Wait for user to input the "enter" key to continue 
void suspend(void) {
	printf("<ENTER> to continue...");
	clearInputBuffer();
	putchar('\n');
}

int inputInt(void) {
	char newLine = 'x';
	int  value;

	while (newLine != '\n') {
		scanf("%d%c", &value, &newLine);
		if (newLine != '\n') {
			clearInputBuffer();
			printf("Error! Input a whole number: ");
		}
	}
	return value;
}

int inputIntPositive() {
	int value;

	do {
		value = inputInt();
		if (value <= 0) {
			printf("ERROR! Value must be > 0: ");
		}
	} while (value <= 0);
	return value;
}

int inputIntRange(int lowerBound, int upperBound) {
	int  value;

	do {
		value = inputInt();
		if (value < lowerBound || value > upperBound) {
			printf("ERROR! Value must be between %d and %d inclusive: ", lowerBound, upperBound);
		}
	} while (value < lowerBound || value > upperBound);

	return value;
}

char inputCharOption(const char validChar[]) {
	int i;
	int valid;
	char character;
	do {

		scanf(" %c", &character);

		valid = 0;
		for (i = 0; validChar[i] != '\0'; i++) {
			if (character == validChar[i]) {
				valid = 1;
			}
		}
		if (valid == 0) {
			printf("ERROR: Character must be one of [qwErty]: ");
		}
		clearInputBuffer();

	} while (valid == 0);
	return character;
}

void inputCString(char* word, int minimum, int maximum) {

	int i;
	char checkWord[80];
	int count;
	int valid = 1;
	do {

		scanf("%[^\n]s", checkWord);

		// count how many characters the user will input
		count = 0;
		for (i = 0; checkWord[i] != '\0'; i++) {
			//printf("%c|\n", checkWord[i]);
			count++;
		}
		//printf("\n=========== count: %d:\n", count);

		if (minimum == maximum && maximum != count) {
			printf("ERROR: String length must be exactly %d chars: ", maximum);
			valid = 0;
		}
		else if (count > maximum) {
			printf("ERROR: String length must be no more than %d chars: ", maximum);
			valid = 0;
		}
		else if (count < minimum || count> maximum) {
			printf("ERROR: String length must be between %d and %d chars: ", minimum, maximum);
			valid = 0;
		}
		else {
			valid = 1;
		}

		clearInputBuffer();

	} while (valid == 0);

	//for (i = 0; checkWord[i] != '\0'; i++) {
	//	word[i] = checkWord[i];
	//}
	strcpy(word, checkWord);

}

void displayFormattedPhone(const char phoneNumber[]) {
	int i;
	int valid = 1; // initialization.
	int count;

	// The program should display "(___)___-____" in the following scenarios:
	// - PhoneNumber variable is null
	// - It is not a 10-character 
	// - The characters ar NOT digit value.
	if (phoneNumber == NULL) {
		valid = 0; // not valid
	}
	else {
		// Checking how many characteres
		// Cannot use strlen() function. Instead we will count each character via for loop
		count = 0;
		for (i = 0; phoneNumber[i] != '\0'; i++) {
			count++;
		}

		// Checking if phoneNumber has 10 characters
		if (count != 10) {
			valid = 0; // not valid
		}
		else {
			// Checking if all the characters are digits or not
			// The C language has a function isDigit(), that returns 0 or 1 indicating if the
			//   character is a digit or not. However I am not sure if we can use isDigit()
			//   in this workshop. The alternative is to check the ASCII table:
			//   48=0 49=1 50=2 51=3 52=4 53=5 54=6 55=7 56=8 57=9      
			for (i = 0; i < 10; i++) {
				// The for loop is i<10 because here we are sure phoneNumber lenght is 10, because we have validated it before.

				if (phoneNumber[i] < 48 || phoneNumber[i] > 57) { // ascii table
					valid = 0; // not valid
				}
			} // end for
		} // end else (count != 10)
	}

	if (valid == 0) {
		printf("(___)___-____");
	}
	else {
		printf("(%c%c%c)%c%c%c-%c%c%c%c",
			phoneNumber[0], phoneNumber[1], phoneNumber[2], // 1st part: (###)
			phoneNumber[3], phoneNumber[4], phoneNumber[5], // 2nd part: ###-
			phoneNumber[6], phoneNumber[7], phoneNumber[8], phoneNumber[9]  // 3rd part: ####
		);
	}

}