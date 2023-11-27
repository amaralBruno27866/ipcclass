/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P2)
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
    //Variables
    char type1 = 'l', type2 = 'R', type3 = 'm', cream1 = 'y', cream2 = 'N', cream3 = 'n', cream4 = 'y', cream5 = 'n', coffee1 = 'L', coffee2 = 'M';
    int gr1=250, gr2=500, gr3=1000, daily1=2, daily2=12;

    // You will need this when converting from grams to pounds (lbs)
    const double GRAMS_IN_LBS = 453.5924;

    //Display results
    printf("Take a Break - Coffee Shop\n");
    printf("==========================\n\n");
    printf("Enter the coffee product information being sold today...\n\n");
    //Order 1 
    printf("COFFEE-1...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): %c\n", type1);
    printf("Bag weight (g): %d\n", gr1);
    printf("Best served with cream ([Y]es,[N]o): %c\n\n", cream1);
 
    //Order 2
    printf("COFFEE-2...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): %c\n", type2);
    printf("Bag weight (g): %d\n", gr2);
    printf("Best served with cream ([Y]es,[N]o): %c\n\n", cream2);
        
    //Order 3    
    printf("COFFEE-3...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): %c\n", type3);
    printf("Bag weight (g): %d\n", gr3);
    printf("Best served with cream ([Y]es,[N]o): %c\n\n", cream3);
    
    printf(
        "---+------------------------+---------------+-------+\n"
        "   |    Coffee              |   Packaged    | Best  |\n"
        "   |     Type               |  Bag Weight   | Served|\n"
        "   +------------------------+---------------+ With  |\n"
        "ID | Light | Medium | Rich  |  (G) | Lbs    | Cream |\n"
        "---+------------------------+---------------+-------|\n"
    );
    printf(" 1 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n"
        , type1 == 'l'
        , type2 != 'R'
        , type3 != 'm'
        , gr1
        , gr1 / GRAMS_IN_LBS
        , cream1 == 'y' || cream1 == 'Y'
    );
    printf(" 2 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n"
        , type1 != 'l'
        , type2 != 'R'
        , type3 == 'm'
        , gr2
        , gr2 / GRAMS_IN_LBS
        , cream2 == 'y' || cream2 == 'Y'
        );
    printf(" 3 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n"
        , type1 != 'l'
        , type2 == 'R'
        , type3 != 'm'
        , gr3
        , gr3 / GRAMS_IN_LBS
        , cream3 == 'y' || cream3 == 'Y'
        );

    printf("\nEnter how you like your coffee...\n\n");

    //Coffee 1
    printf("Coffee strength ([L]ight, [M]edium, [R]ich): %c\n", coffee1);
    printf("Do you like your coffee with cream ([Y]es,[N]o): %c\n", cream4);
    printf("Typical number of daily servings: %d\n", daily1);

    printf("\nThe below table shows how your preferences align to the available products:\n\n");
    printf(
        "--------------------+-------------+-------+\n"
        "  |     Coffee      |  Packaged   | With  |\n"
        "ID|      Type       | Bag Weight  | Cream |\n"
        "--+-----------------+-------------+-------+\n"
    );
    printf(" 1|       %d         |      %d      |   %d   |\n"
        , coffee1 == 'L'
        , cream4 == 'y'
        , daily1 != 0
    );
    printf(" 2|       0         |      0      |   0   |\n");
    printf(" 3|       0         |      0      |   0   |\n");

    printf("\nEnter how you like your coffee...\n\n");
    //Coffee 2
    printf("Coffee strength ([L]ight, [M]edium, [R]ich): %c\n", coffee2);
    printf("Do you like your coffee with cream ([Y]es,[N]o): %c\n", cream5);
    printf("Typical number of daily servings: %d\n", daily2);

    printf("\nThe below table shows how your preferences align to the available products:\n\n");
    
    printf(
        "--------------------+-------------+-------+\n"
        "  |     Coffee      |  Packaged   | With  |\n"
        "ID|      Type       | Bag Weight  | Cream |\n"
        "--+-----------------+-------------+-------+\n"
    );
    printf(" 1|       0         |      0      |   0   |\n");
    printf(" 2|       0         |      0      |   1   |\n");
    printf(
        " 3|       %d         |      %d      |   %d   |\n\n"
        , coffee2 == 'M'
        , cream5 == 'n'
        , daily1 != 0
    );

    printf("Hope you found a product that suits your likes!\n");

    return 0;
}


/*

Provided formatting parts for printf statements:

As described in step-7
======================
printf(" 1 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n",

As described in step-10
=======================
printf(" 1|       %d         |      %d      |   %d   |\n",

*/