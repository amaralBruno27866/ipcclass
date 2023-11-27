/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P1)
Full Name  : Bruno Alencar Amaral
Student ID#: 143766228
Email      : bamaral2@myseneca.ca
Section    : ZFF

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#include <stdio.h>

int main(void){

    //Variables
    const int product1 = 111, product2 = 222, product3 = 111;
    const double priceProduct1 = 111.49, priceProduct2 = 222.99, priceProduct3 = 334.49;
    const char tax1 = 'Y', tax2 = 'N', tax3 = 'N';

    const double averagePrice = (priceProduct1 + priceProduct2 + priceProduct3) / 3;

    // You must use this variable in #3 data analysis section!
    const double testValue = 330.99;

    //Display
    printf(
        "Product Information\n"
        "===================\n"
        "Product-1 (ID:%d)\n"
        "  Taxed: %c\n"
        "  Price: $%.4f\n\n"
        ,product1, tax1, priceProduct1   
    );

    printf(
        "Product-2 (ID:%d)\n"
        "  Taxed: %c\n"
        "  Price: $%.4f\n\n"
        ,product2, tax2, priceProduct2
    );

    printf(
        "Product-3 (ID:%d)\n"
        "  Taxed: %c\n"
        "  Price: $%.4f\n\n"
        ,product3, tax3, priceProduct3
    );

    printf(
        "The average of all prices is: $%.4f\n\n"
        , averagePrice
    );

    //About Relational and Logical Expressions!
    printf(
        "About Relational and Logical Expressions!\n"
        "========================================\n"
        "1. These expressions evaluate to TRUE or FALSE\n"
        "2. FALSE: is always represented by integer value 0\n"
        "3. TRUE : is represented by any integer value other than 0\n\n"
    );

    printf(
        "Some Data Analysis...\n"
        "=====================\n"
    );

    printf(
        "1. Is product 1 taxable? -> %d\n\n"
        , tax1 == 'Y'
    );

    printf(
        "2. Are products 2 and 3 both NOT taxable (N)? -> %d\n\n"
        , tax2 && tax3 == 'N'
    );
        
    printf(
        "3. Is product 3 less than testValue ($%.2f)? -> %d\n\n"
        , testValue, testValue == priceProduct3
    );

    printf(
        "4. Is the price of product 3 more than both product 1 and 2 combined? -> %d\n\n"
        , priceProduct1 + priceProduct2 < priceProduct3
    );

    printf(
        "5. Is the price of product 1 equal to or more than the price difference\n"
        "   of product 3 LESS product 2? ->  %d (price difference: $%.2f)\n\n"
        , (priceProduct1 >= (priceProduct3 - priceProduct2)), (priceProduct3 - priceProduct2)
    );

    printf(
        "6. Is the price of product 2 equal to or more than the average price? -> %d\n\n"
        , (priceProduct3 > (priceProduct1 + priceProduct2))
    );

    printf(
        "7. Based on product ID, product 1 is unique -> %d\n\n"
        , product1 != product2 && product1 != product3 && product2 != product3
    );

    printf(
        "8. Based on product ID, product 2 is unique -> %d\n\n"
        , product2 != product1 || product3
    );

    printf(
        "9. Based on product ID, product 3 is unique -> %d\n"
        , product3 != product1 && product3 != product2 && product2 != product1
    );

    return 0;
}