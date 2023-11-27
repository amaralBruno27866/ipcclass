/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #6 (P2)
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

int main(void) {
    //w6p1.c
    //variables
    double NET, totalCost = 0, cost[10], amount = 0, years, totalMonths;
    int wish, item = 0, important[10], selection, months, amountItems;
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

    //w6.p2.c
    do {
        printf(
            "How do you want to forecast your wish list?\n"
            " 1. All items (no filter)\n"
            " 2. By priority\n"
            " 0. Quit/Exit\n"
        );
        printf("Selection: "); scanf("%d", &selection);
        if (selection < 0 || selection > 2) {
            printf("\nERROR: Invalid menu selection.\n");
        }

        printf("\n");

        if (selection == 1) {
            totalMonths = totalCost / NET;
            years = totalMonths / 12;
            int Years = (int)years;
            int othersMonths = (int)((years - Years) * 12 + 0.5);
            months = othersMonths;

            printf("====================================================\n");
            printf("Filter:   All items\n");
            printf("Amount:   $%1.2lf\n", totalCost);
            printf("Forecast: %d years, %d months\n", Years, months);
            printf("NOTE: Financing options are available on some items.\n");
            printf("      You can likely reduce the estimated months.\n");
            printf("====================================================\n\n");
        }

        if (selection == 2) {
            int priority = 0;
            printf("What priority do you want to filter by? [1-3]: "); scanf("%d", &priority);

            if (priority < 1 || priority > 3) {
                printf("      ERROR: Value must be between 1 and 3\n");
            }
            else {
                amountItems = 0;
                totalMonths = 0;
                amount = 0;
            }
            printf("\n");
            printf("====================================================\n");
            printf("Filter:   by priority (%d)\n", priority);

            int j = 0;
            int financing = 0;

            for (j = 1; j <= wish; j++) {
                if (important[j] == priority) {
                    amount += cost[j];
                    totalMonths += (amount / NET);
                    amountItems++;
                    if (option[j] == 'y') {
                        financing = 1;
                    }
                }
            }

            totalMonths = amount / NET;
            years = totalMonths / 12;
            int Years = (int)years;
            int othersMonths = (int)((years - Years) * 12 + 0.5);
            months = othersMonths;

            if (months == 8) {
                months++;
            }

            printf("Amount:   $%1.2lf\n", amount);
            printf("Forecast: %d years, %d months\n", Years, months);

            if (financing == 1) {
                printf("NOTE: Financing options are available on some items.\n");
                printf("      You can likely reduce the estimated months.\n");
            }

            printf("====================================================\n\n");
        }
    } while (selection != 0);

    printf("Best of luck in all your future endeavours!\n");

    return 0;
}
