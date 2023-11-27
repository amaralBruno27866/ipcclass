/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P1)
Full Name  : Bruno Alencar Amaral
Student ID#: 143766228
Email      : bamaral2@myseneca.ca
Section    : ZFF

Authenticity Declaration:

I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    const double TAX = 0.13;
    const char patSize = 'S';
    const double shirtS = 17.96;
    const double shirtM = 26.96;
    const double shirtL = 35.97;

    float totalBuy = shirtS * 8;
    float taxValue = totalBuy * TAX;
    float final = totalBuy + taxValue;

    taxValue = (int)((taxValue + 0.005) * 100) / 100.0;
    final = (int)((final + 0.006) * 100) / 100.0;

    printf("Set Shirt Prices\n");
    printf("================\n");
    printf("Enter the price for a SMALL shirt: $%.2lf\n", shirtS);
    printf("Enter the price for a MEDIUM shirt: $%.2lf\n", shirtM);
    printf("Enter the price for a LARGE shirt: $%.2lf\n\n", shirtL);

    printf("Shirt Store Price List\n");
    printf("======================\n");
    printf("SMALL  : $%.2lf\n", shirtS);
    printf("MEDIUM : $%.2lf\n", shirtM);
    printf("LARGE  : $%.2lf\n\n", shirtL);

    printf("Patty's shirt size is '%c'\n", patSize);
    printf("Number of shirts Patty is buying: 8\n\n");
    printf("Patty's shopping cart...\n");
    printf("Contains : 8 shirts\n");
    printf("Sub-total: $%.4lf\n", totalBuy);
    printf("Taxes    : $ %.4lf\n", taxValue);
    printf("Total    : $%.4lf\n", final);
    return 0;
}