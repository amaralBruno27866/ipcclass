/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #4 (P1)
Full Name  : Noor Uddin Syed
Student ID#: 118642222
Email      : nsyed19@myseneca.ca
Section    : ZII

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {

	//Variables
	int val1;
	char x;

	printf(
		"+----------------------+\n"
		"Loop application STARTED\n"
		"+----------------------+\n\n"
	);
	do {

		printf("D = do/while | W = while | F = for | Q = quit\n");

		printf("Enter loop type and the number of times to iterate (Quit=Q0): "); scanf(" %c%d", &x, &val1);

		if (x == 'Q') {
			if (val1 == 0) {
				printf(
					"\n+--------------------+\n"
					"Loop application ENDED\n"
					"+--------------------+\n"
				);
				return 0;
			}
			else {
				if (val1 < 0 || val1 == 1 || val1 <= 2) {
					printf("ERROR: To quit, the number of iterations should be 0!\n\n");
				}
			}
		}
		if (x != 'D' && x != 'W' && x != 'F' && x != 'Q') {
			printf("ERROR: Invalid entered value(s)!\n\n");
		}
		else {
			if (val1 > 1) {
				if (val1 < 3 || val1 > 20) {
					printf("ERROR: The number of iterations must be between 3-20 inclusive!\n\n");
				}
				else {
					switch (x) {
					case 'D':
						printf("DO-WHILE: ");
						do {
							val1--;
							printf("D");
						} while (val1 > 0);
						printf("\n\n");
						break;
					case 'W':
						printf("WHILE   : ");
						while (val1 > 0)
						{
							val1--;
							printf("W");
						};
						printf("\n\n");
						break;
					case 'F':
						printf("FOR     : ");
						do {
							val1--;
							printf("F");
						} while (val1 > 0);
						printf("\n\n");
						break;
					default:

						break;
					}
				}
			}
		}
	} while (1);

	return 0;
}
