/*
*****************************************************************************
                          Workshop - #4 (P2)
Full Name  : Noor Uddin Syed
Student ID#: 118642222
Email      : nsyed19@myseneca.ca
Section    : ZII

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
	//Variables
	int  apple, orange, pear, tomatoe, cabbage;
	int Apple[10], Orange[20], Pear[5], Tomatoe[15], Cabbage[15];
	int sum, count;
	int exit;


	//Start
	do {
		printf("Grocery Shopping\n");
		printf("================\n");
		
		//Shopping list
		do {
			printf("How many APPLES do you need? : "); scanf("%d", &apple);

			if (apple < 0) {
				printf("ERROR: Value must be 0 or more.\n");
			}
		} while (apple < 0);
		printf("\n");

		do {
			printf("How many ORANGES do you need? : "); scanf("%d", &orange);

			if (orange < 0) {
				printf("ERROR: Value must be 0 or more.\n");
			}
		} while (orange < 0);
		printf("\n");

		do {
			printf("How many PEARS do you need? : "); scanf("%d", &pear);

			if (pear < 0) {
				printf("ERROR: Value must be 0 or more.\n");
			}
		} while (pear < 0);
		printf("\n");

		do {
			printf("How many TOMATOES do you need? : "); scanf("%d", &tomatoe);

			if (tomatoe < 0) {
				printf("ERROR: Value must be 0 or more.\n");
			}
		} while (tomatoe < 0);
		printf("\n");

		do {
			printf("How many CABBAGES do you need? : "); scanf("%d", &cabbage);

			if (cabbage < 0) {
				printf("ERROR: Value must be 0 or more.\n");
			}
		} while (cabbage < 0);
		printf("\n");

		//Pick up products
		printf("--------------------------\n");
		printf("Time to pick the products!\n");
		printf("--------------------------\n\n");

		//Apples
		if (apple != 0) {
			sum = 0;
			count = 0;
			while (sum < 10) {
				printf("Pick some APPLES... how many did you pick? : "); scanf("%d", &Apple[count]);

				if (Apple[count] < 1) {
					printf("ERROR: You must pick at least 1!\n");
				}
				else if (sum + Apple[count] > 10) {
					printf("You picked too many... only %d more APPLE(S) are needed.\n", 10 - sum);
				}
				else {
					sum += Apple[count];
					count++;
					if (sum < 10) {
						printf("Looks like we still need some APPLES...\n");
					}
					else {
						printf("Great, that's the apples done!\n\n");
					}
				}
			}
		}

		//Oranges
		if (orange != 0) {
			sum = 0;
			count = 0;
			while (sum < 20) {
				printf("Pick some ORANGES... how many did you pick? : "); scanf("%d", &Orange[count]);

				if (Orange[count] < 1) {
					printf("ERROR: You must pick at least 1!\n");
				}
				else if (sum + Orange[count] > 20) {
					printf("You picked too many... only %d more ORANGE(S) are needed.\n", 20 - sum);
				}
				else {
					sum += Orange[count];
					count++;
					if (sum < 20) {
						printf("Looks like we still need some ORANGES...\n");
					}
					else {
						printf("Great, that's the oranges done!\n\n");
					}
				}
			}
		}

		//Pears
		if (pear != 0) {
			sum = 0;
			count = 0;
			while (sum < 5) {
				printf("Pick some PEARS... how many did you pick? : "); scanf("%d", &Pear[count]);

				if (Pear[count] < 1) {
					printf("ERROR: You must pick at least 1!\n");
				}
				else if (sum + Pear[count] > 5) {
					printf("You picked too many... only %d more PEAR(S) are needed.\n", 5 - sum);
				}
				else {
					sum += Pear[count];
					count++;
					if (sum < 5) {
						printf("Looks like we still need some PEARS...\n");
					}
					else {
						printf("Great, that's the pears done!\n\n");
					}
				}
			}
		}

		//Tomatoes
		if (tomatoe != 0) {
			sum = 0;
			count = 0;
			while (sum < 15) {
				printf("Pick some TOMATOES... how many did you pick? : "); scanf("%d", &Tomatoe[count]);

				if (Tomatoe[count] < 1) {
					printf("ERROR: You must pick at least 1!\n");
				}
				else if (sum + Tomatoe[count] > 15) {
					printf("You picked too many... only %d more TOMATO(ES) are needed.\n", 15 - sum);
				}
				else {
					sum += Tomatoe[count];
					count++;
					if (sum < 15) {
						printf("Looks like we still need some TOMATOES...\n");
					}
					else {
						printf("Great, that's the tomatoes done!\n\n");
					}
				}
			}
		}

		//Cabbages
		if (cabbage != 0) {
			sum = 0;
			count = 0;
			while (sum < 15) {
				printf("Pick some CABBAGES... how many did you pick? : "); scanf("%d", &Cabbage[count]);

				if (Cabbage[count] < 1) {
					printf("ERROR: You must pick at least 1!\n");
				}
				else if (sum + Cabbage[count] > 15) {
					printf("You picked too many... only %d more CABBAGES(S) are needed.\n", 15 - sum);
				}
				else {
					sum += Cabbage[count];
					count++;
					if (sum < 15) {
						printf("Looks like we still need some CABBAGES...\n");
					}
					else {
						printf("Great, that's the cabbages done!\n\n");
					}
				}
			}
		}
		printf("All the items are picked!\n\n");
		printf("Do another shopping? (0=NO): "); scanf(" %d", &exit);
		if (exit == 0) {
			printf("\nYour tasks are done for today - enjoy your free time!\n");
			return 0;
		}
		printf("\n");

	}while (1);

	return 0;
}