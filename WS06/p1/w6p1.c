/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #6 (P1)
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
#define MIN_NET 500.00
#define MAX_NET 400000.00

#include <stdio.h>

int main(void)
{
    //variables
    double NET, totalCost = 0, cost[10];
    int wish, item = 0, important[10];
    char option[10];

    //function
    printf(
        "+--------------------------+\n"
        "+   Wish List Forecaster   |\n"
        "+--------------------------+\n"
    );

    //input NET monthly
    do {
        printf("\nEnter your monthly NET income: $"); scanf("%lf", &NET);

        if (NET < MIN_NET) {
            printf("ERROR: You must have a consistent monthly income of at least $500.00\n");
        }
        if (NET > MAX_NET) {
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n");
        }
    } while (NET < MIN_NET || NET > MAX_NET);

    //input number of wish list items
    do {
        printf("\nHow many wish list items do you want to forecast?: "); scanf("%d", &wish);

        if (wish < 1 || wish > 10) {
            printf("ERROR: List is restricted to between 1 and 10 items.\n");
        }
    } while (wish < 1 || wish > 10);

    printf("\n");

    //input detail for wish list
    int i = 0;
    item = 1;

    while (item <= wish) {
        printf("Item-%d Details:\n", item);

        do {
            printf("   Item cost: $"); scanf("%lf", &cost[item]);
            if (cost[item] < 100) {
                printf("      ERROR: Cost must be at least $100.00\n");
            }
        } while (cost[item] < 100);

        do {
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: "); scanf("%d", &important[item]);
            if (important[item] < 1 || important[item] > 3) {
                printf("      ERROR: Value must be between 1 and 3\n");
            }
        } while (important[item] < 1 || important[item] > 3);

        do {
            printf("   Does this item have financing options? [y/n]: "); scanf(" %c", &option[item]);
            if (option[item] != 'y' && option[item] != 'n') {
                printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
            }
        } while (option[item] != 'y' && option[item] != 'n');

        printf("\n");

        item++;
    }

    //sumary
    printf("Item Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");

    int j;
    for (j = 1; j <= wish; j++) {
        printf("%3d  %5d    %5c    %11.2lf\n", j, important[j], option[j], cost[j]);
        totalCost += cost[j];
    }

    printf("---- -------- -------- -----------\n");
    printf("                      $%11.2lf\n\n", totalCost);

    printf("Best of luck in all your future endeavours!");

    return 0;
}
