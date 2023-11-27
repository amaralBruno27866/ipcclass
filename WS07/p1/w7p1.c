/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #7 (P1)
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
#define MAX_LENGHT 70
#define MIN_LENGHT 10
#define ARRAY_LENGHT (MAX_LENGHT - MIN_LENGHT + 1)

struct PlayerInfo {
    int lifes, treasure, history;
    char character;
};

struct PlayerInfo player;

struct GameInfo {
    int moves, lenght;
};

struct GameInfo game;

#include <stdio.h>

int main(void) {

    int repeat, x = 1, y = 0, pMovesINT, auxBomb = 0, auxTreasure = 0;
    int bombPosition[MAX_LENGHT], treasure[MAX_LENGHT];
    double pMoves;

    //data input
    //setup for player and game
    /*-------------------------------------------------------------------------------------------------------------------*/
    player.history = 0;
    player.lifes = 0;
    player.treasure = 0;

    game.lenght = 0;
    game.moves = 0;

    printf(
        "================================\n"
        "         Treasure Hunt!\n"
        "================================\n\n"
    );

    printf("PLAYER Configuration\n");
    printf("--------------------\n");
    printf("Enter a single character to represent the player: "); scanf(" %c", &player.character);
    do {
        printf("Set the number of lives: "); scanf("%d", &player.lifes);
        if (player.lifes < 1 || player.lifes > 10) {
            printf("     Must be between 1 and 10!\n");
        }
        else {
            printf("Player configuration set-up is complete\n\n");
        }
    } while (player.lifes < 1 || player.lifes > 10);

    printf("GAME Configuration\n");
    printf("------------------\n");
    do {
        printf("Set the path length (a multiple of 5 between 10-70): "); scanf("%d", &game.lenght);
        if (game.lenght < MIN_LENGHT || game.lenght > MAX_LENGHT || game.lenght % 5 != 0) {
            printf("     Must be a multiple of 5 and between 10-70!!!\n");
        }
    } while (game.lenght < MIN_LENGHT || game.lenght > MAX_LENGHT || game.lenght % 5 != 0);

    do {
        printf("Set the limit for number of moves allowed: "); scanf("%d", &game.moves);
        pMoves = game.lenght * 0.75;
        pMovesINT = (int)pMoves;
        if (game.moves < player.lifes || game.moves > pMoves) {
            printf("    Value must be between %d and %d\n", player.lifes, pMovesINT);
        }
    } while (game.moves < player.lifes || game.moves > pMoves);

    printf("\n");

    //setup bombs and treasure
    /*-------------------------------------------------------------------------------------------------------------------*/
    printf("BOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of 5 where a value\n");
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.lenght);

    repeat = game.lenght / 5;

    do {
        y = x + 4;

        if (x == 1) {
            printf("   Positions [ %d- %d]: ", x, y);
        }
        if (x == 6) {
            printf("   Positions [ %d-%d]: ", x, y);
        }
        if (x > 6) {
            printf("   Positions [%d-%d]: ", x, y);
        }

        int i = 0;
        while(i < 5) {
            scanf("%d", &bombPosition[auxBomb + i]);
            i++;
        }

        repeat--;

        x = y + 1;

    } while (repeat > 0);

    printf("BOMB placement set\n\n");

    printf("TREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of 5 where a value\n");
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.lenght);

    repeat = game.lenght / 5;
    x = 1;
    y = 0;

    do {
        y = x + 4;

        if (x == 1) {
            printf("   Positions [ %d- %d]: ", x, y);
        }
        if (x == 6) {
            printf("   Positions [ %d-%d]: ", x, y);
        }
        if (x > 6) {
            printf("   Positions [%d-%d]: ", x, y);
        }

        int j = 0;
        while(j < 5) {
            scanf("%d", &treasure[auxTreasure + j]);
            j++;
        }

        repeat--;

        x = y + 1;

    } while (repeat > 0);
    printf("TREASURE placement set\n\n");

    printf("GAME configuration set-up is complete...\n\n");

    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");
    printf("Player:\n");
    printf("   Symbol     : %c\n", player.character);
    printf("   Lives      : %d\n", player.lifes);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n\n");

    printf("Game:\n");
    printf("   Path Length: %d\n", game.lenght);
    printf("   Bombs      : 00001100111011101000101000001010101\n");
    printf("   Treasure   : 00100111011101001000110101010001111\n\n");

    printf("====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n");

    return 0;
}