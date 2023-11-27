/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #5 (P1)
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
#define MIN_YEAR 2012
#define MAX_YEAR 2022
#include <stdio.h>

int main(void)
{

	//Variables
	const int JAN = 1, DEC = 12;
	int y, m, error = 0;
	char* month;

	//Title
	printf(
		"General Well-being Log\n"
		"======================\n"
	);

	//Function
	do {
		printf("Set the year and month for the well-being log (YYYY MM): "); scanf("%d %d", &y, &m);

		error = 0;

		if (y < MIN_YEAR || y > MAX_YEAR) {
			printf("   ERROR: The year must be between 2012 and 2022 inclusive\n");
			error = 1;
		}
		if (m < JAN || m > DEC) {
			printf("   ERROR: Jan.(1) - Dec.(12)\n");
			error = 1;
		}
		if (error == 0) {
			break;
		}
	} while (1);

	printf("\n*** Log date set! ***\n\n");

	switch (m) {
	case 1:
		month = "JAN";
		break;
	case 2:
		month = "FEB";
		break;
	case 3:
		month = "MAR";
		break;
	case 4:
		month = "APR";
		break;
	case 5:
		month = "MAY";
		break;
	case 6:
		month = "JUN";
		break;
	case 7:
		month = "JUL";
		break;
	case 8:
		month = "AUG";
		break;
	case 9:
		month = "SEP";
		break;
	case 10:
		month = "OCT";
		break;
	case 11:
		month = "NOV";
		break;
	case 12:
		month = "DEC";
		break;
	default:
		month = " ";
		break;
	}

	printf("Log starting date: %d-%s-01\n", y, month);

	return 0;
}