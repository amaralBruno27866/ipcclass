/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #5 (P2)
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
#define LOG_DAYS 3
#include <stdio.h>

int main(void)
{

	//Variables
	const int jan = 1, dec = 12;
	int y, m, error = 0;
	float morning, evening , sumMorning = 0.0, sumEvening = 0.0, morningnAverage = 0.0, eveningnAverage = 0.0, average = 0.0;
	char* month;

	//Title
	printf(
		"General Well-being Log\n"
		"======================\n"
	);

	//Function input user
	do {
		printf("Set the year and month for the well-being log (YYYY MM): "); scanf("%d %d", &y, &m);

		error = 0;

		if (y < MIN_YEAR || y > MAX_YEAR) {
			printf("   ERROR: The year must be between 2012 and 2022 inclusive\n");
			error = 1;
		}
		if (m < jan || m > dec) {
			printf("   ERROR: Jan.(1) - Dec.(12)\n");
			error = 1;
		}
		if (error == 0) {
			break;
		}
	} while (1);

	//Function check month
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

	//Function Morning Evening
	int i = 1;

	while (i <= LOG_DAYS) {
		printf("%d-%s-0%d\n", y, month, i);
		do {
			printf("   Morning rating (0.0-5.0): "); scanf("%f", &morning);
			if (morning < 0 || morning > 5) {
				printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
			}
		} while (morning < 0 || morning > 5);

		do {
			printf("   Evening rating (0.0-5.0): "); scanf("%f", &evening);
			if (evening < 0 || evening > 5) {
				printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
			}
		} while (evening < 0 || evening > 5);

		printf("\n");

		sumMorning += morning;
		sumEvening += evening;

		i++;
	}

	//Sumary
	printf("Summary\n");
	printf("=======\n");
	printf("Morning total rating: %.3f\n", sumMorning);
	printf("Evening total rating:  %.3f\n", sumEvening);
	printf("----------------------------\n");
	printf("Overall total rating: %.3f\n", (sumMorning + sumEvening));
	
	//Calc sumary average
	morningnAverage = sumMorning / LOG_DAYS;
	eveningnAverage = sumEvening / LOG_DAYS;
	average = (morningnAverage + eveningnAverage) / 2;

	printf("\nAverage morning rating:  %.1f\n", morningnAverage);
	printf("Average evening rating:  %.1f\n", eveningnAverage);
	printf("----------------------------\n");
	printf("Average overall rating:  %.1f\n", average);

	return 0;
}