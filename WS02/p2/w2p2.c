/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P2)
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
    //const double TAX = 0.13;
    //const char patSize = 'S', salSize = 'M', tomSize = 'L';

    const double TAX = 0.13, shirtS = 17.96, shirtM = 26.96, shirtL = 35.97;

    const char patSize = 'S', salSize = 'M', tomSize = 'L';

    const int patty = 6, tommy = 3, sally = 4;

    ///////////////Calc subtotal///////////////
//Iten 1 Patty
    double calc1 = shirtS * patty;
    double tax1 = calc1 * TAX;
    double totalA = calc1 + tax1;

    //Iten 2 Sally
    double calc2 = shirtM * tommy;
    double tax2 = calc2 * TAX;
    double totalB = calc2 + tax2;

    //Iten 3 Tommy
    double calc3 = shirtL * sally;
    double tax3 = calc3 * TAX;
    double totalC = calc3 + tax3;

    //Final calculation
    double subTotal = calc1 + calc2 + calc3;
    double totalTAX = tax1 + tax2 + tax3;
    double total = totalA + totalB + totalC;

    printf(
        "Set Shirt Prices\n"
        "================\n"
        "Enter the price for a SMALL shirt: $%.2lf\n"
        "Enter the price for a MEDIUM shirt: $%.2lf\n"
        "Enter the price for a LARGE shirt: $%.2lf\n\n"

        , shirtS, shirtM, shirtL
    );

    printf(
        "Shirt Store Price List\n"
        "======================\n"
        "SMALL  : $%.2lf\n"
        "MEDIUM : $%.2lf\n"
        "LARGE  : $%.2lf\n\n"

        , shirtS, shirtM, shirtL
    );

    printf(
        "Patty's shirt size is '%c'\n"
        "Number of shirts Patty is buying: %i\n\n"
        "Tommy's shirt size is '%c'\n"
        "Number of shirts Tommy is buying: %i\n\n"
        "Sally's shirt size is '%c'\n"
        "Number of shirts Sally is buying: %i\n\n"

        , patSize, patty, tomSize, tommy, salSize, sally
    );

    printf(
        "Customer Size Price Qty Sub-Total       Tax     Total\n"
        "-------- ---- ----- --- --------- --------- ---------\n"
        "Patty    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n\n"
        , patSize, shirtS, patty, calc1, tax1, totalA
    );

    printf(
        "Sally    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n\n"
        , salSize, shirtM, sally, calc2, tax2, totalB
    );

    printf(
        "Tommy    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n"
        , tomSize, shirtL, tommy, calc3, tax3, totalC
    );

    printf(
        "-------- ---- ----- --- --------- --------- ---------\n"
        "%33.4lf %9.4lf %9.4lf\n\n"
        , subTotal, totalTAX, total
    );

    double costShirt1 = subTotal / (patty + tommy + sally);

    printf(
        "Daily retail sales represented by coins\n"
        "=======================================\n\n"
        "Sales EXCLUDING tax\n"
        "Coin     Qty   Balance\n"
        "-------- --- ---------\n"
        "             %9.4lf\n"
        "Toonies  161 1.5100\n"
        "Loonies    1 0.5100\n"
        "Quarters   2 0.0100\n"
        "Dimes      0 0.0100\n"
        "Nickels    0 0.0100\n"
        "Pennies    1 0.0000\n\n"
        , subTotal
    );

    printf("Average cost/shirt: $%9.4lf\n\n", costShirt1);

    double costShirt2 = total / (patty + tommy + sally);

    printf(
        "Sales INCLUDING tax\n"
        "Coin     Qty Balance\n"
        "-------- --- ---------\n"
        "             %9.4lf\n"
        "Toonies  182 1.5700\n"
        "Loonies    1 0.5700\n"
        "Quarters   2 0.0700\n"
        "Dimes      0 0.0700\n"
        "Nickels    1 0.0200\n"
        "Pennies    2 0.0000\n\n"
        "Average cost/shirt: $%9.4lf\n"
        , total, costShirt2
    );

    return 0;
}