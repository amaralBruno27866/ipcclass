/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #7 (P2)
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
#define MAX_MOVES 70
#define MIN_MOVES 10
#define SIZE 5

#include <stdio.h>

//STRUCTURE
struct PlayerInfo {
	int lives, treasure, moves;
	char character;
};
struct PlayerInfo player;

struct GameSettings {
	int moves, length;
};
struct GameSettings game;

//VARIABLES
int bombs[MAX_MOVES][SIZE];
int treasure[MAX_MOVES][SIZE];
int history[MAX_MOVES];
int positions, walk, result, walk = 0;

//FUNCTIONS
void setCharacter(struct PlayerInfo* player);
void setLives();
void setGameLength();
void movesAllowed();
void setBombs();
void setTreasure();
void summary();
void playingGame();
void line1();
void line2();
void line3();
void line4();
void gamePlay();
void playing();

//VARIABLES
int bombs[MAX_MOVES][SIZE];
int historyCount = 0;

int main(void) {

	printf(
		"================================\n"
		"         Treasure Hunt!\n"
		"================================\n\n"
	);

	setCharacter(&player);

	setLives(&player);

	printf("GAME Configuration\n");
	printf("------------------\n");

	setGameLength(&game);

	movesAllowed(&game, &player);

	printf("\n");

	setBombs();

	printf("\n");

	setTreasure();

	printf("\n");

	summary();

	while (player.lives > 0) {
		while (player.moves > 0) {
			playingGame();
		}
	}

	if (player.lives == 0 || player.moves == 0) {
		printf("##################\n");
		printf("#   Game over!   #\n");
		printf("##################\n");
	}

	printf("\n");

	printf("You should play again and try to beat your score!");

	return 0;
}

void setCharacter(struct PlayerInfo* player) {
	printf("PLAYER Configuration\n");
	printf("--------------------\n");

	printf("Enter a single character to represent the player: "); scanf(" %c", &(player->character));
}

void setLives(struct PlayerInfo* player) {
	do {
		printf("Set the number of lives: "); scanf("%d", &(player->lives));
		if (player->lives < 1 || player->lives > 10) {
			printf("     Must be between 1 and 10!\n");
		}
		else {
			printf("Player configuration set-up is complete\n\n");
		}
	} while (player->lives < 1 || player->lives > 10);
}

void setGameLength(struct GameSettings* game) {
	do {
		printf("Set the path length (a multiple of 5 between 10-70): "); scanf("%d", &(game->length));
		if (game->length < MIN_MOVES || game->length > MAX_MOVES || game->length % 5 != 0) {
			printf("     Must be a multiple of 5 and between 10-70!!!\n");
		}
	} while (game->length < MIN_MOVES || game->length > MAX_MOVES || game->length % 5 != 0);
}

void movesAllowed(struct GameSettings* game, struct PlayerInfo* player) {
	double playerMoves;
	int playerMovesINT;
	do {
		printf("Set the limit for number of moves allowed: "); scanf("%d", &(game->moves));
		player->moves = game->moves;
		playerMoves = game->moves * 0.75;
		playerMovesINT = (int)playerMoves;
		if (game->moves < player->lives || game->moves > player->moves) {
			printf("    Value must be between %d and %d\n", player->lives, playerMovesINT);
		}
	} while (game->moves < player->lives || game->moves > player->moves);
}

void setBombs() {
	int repeat, i = 0, y = 0, x = 1;;
	printf("BOMB Placement\n");
	printf("--------------\n");
	printf("Enter the bomb positions in sets of 5 where a value\n");
	printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
	printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.length);

	positions = game.length / 5;
	repeat = positions;

	while (i < positions) {
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
		while (j < SIZE) {
			scanf("%d", &bombs[i][j]);

			j++;

		}
		i++;
		repeat--;
		x = y + 1;
	}
	printf("\n");
	printf("BOMB placement set\n");
}

void setTreasure() {
	int repeat, a = 0, x = 1, y = 0;
	printf("TREASURE Placement\n");
	printf("------------------\n");
	printf("Enter the treasure placements in sets of 5 where a value\n");
	printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
	printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.length);

	positions = game.length / 5;
	repeat = positions;

	while (a < positions) {
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

		int b = 0;
		while (b < SIZE) {
			scanf("%d", &treasure[a][b]);

			b++;

		}
		a++;
		repeat--;
		x = y + 1;
	}
	printf("\n");
	printf("TREASURE placement set\n");
}

void summary() {
	printf("GAME configuration set-up is complete...\n\n");

	printf("------------------------------------\n");
	printf("TREASURE HUNT Configuration Settings\n");
	printf("------------------------------------\n");
	printf("Player:\n");
	printf("   Symbol     : %c\n", player.character);
	printf("   Lives      : %d\n", player.lives);
	printf("   Treasure   : [ready for gameplay]\n");
	printf("   History    : [ready for gameplay]\n\n");

	printf("Game:\n");
	printf("   Path Length: %d\n", game.length);

	printf("   Bombs      : ");
	int c = 0;
	while (c < positions) {
		int d = 0;
		while (d < SIZE) {
			printf("%d", bombs[c][d]);
			d++;
		}
		c++;
	}

	printf("\n");

	printf("   Treasure   : ");
	int e = 0;
	while (e < positions) {
		int f = 0;
		while (f < SIZE) {
			printf("%d", treasure[e][f]);
			f++;
		}
		e++;
	}

	printf("\n");
	printf("====================================\n");
	printf("~ Get ready to play TREASURE HUNT! ~\n");
	printf("====================================\n");

}

void playingGame() {
	int moving = 0;

	line1();

	line2();

	line3();

	line4();

	printf("+---------------------------------------------------+\n");
	printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", player.lives, player.treasure, player.moves);
	printf("+---------------------------------------------------+\n");

	printf("Next Move [1-%d]: ", game.length); scanf("%d", &moving);

	walk = moving;

	if (moving < 1 || moving > game.length) {
		printf("  Out of Range!!!\n");
	}

	history[historyCount] = moving;
	historyCount++;

	playing();

}

void line1() {
	if (player.lives > 0) {
		for (int i = 0; i < game.length; i++) {
			if (i == walk) {
				printf(" %c", player.character);
			}
			else {
				printf(" ");
			}
		}
	}
	
	printf("\n");
}

void line2() {
	char result = ' ';
	printf("  ");
	for (int i = 0; i < game.length; i++) {
		printf("-");
	}
	if (player.lives > 0) {
		for (int i = 0; i < game.length; i++) {
			if (i == walk - 1) {
				for (int j = 0; j < SIZE; j++) {
					if (bombs[i][j] == 1) {
						printf("!");
						result = '!';
					}
					if (treasure[i][j] == 1) {
						printf("$");
						result = '$';
					}
					if (bombs[i][j] == 1 && treasure[i][j] == 1) {
						printf("&");
						result = '&';
					}
					if (bombs[i][j] == 0 && treasure[i][j] == 0) {
						printf(".");
						result = '.';
					}
				}
			}
		}
	}

	gamePlay();

	result = ' ';

	printf("\n");
}


void line3() {
	int g = 0, n = 1;
	printf("  ");
	while (g < game.length / 10) {
		while (n < positions) {
			for (int i = 0; i < 9; i++) {
				printf("|");
			}
			if (n <= 9) {
				printf("%d", n);
			}
			if (game.length > 10) {
				printf("%d", n);
			}
			n++;
		}
		g++;
	}
	
	printf("\n");
}

void line4() {
	int g = 0;
	printf("  ");
	while (g < game.length / 10) {
		for (int i = 1; i <= 9; i++) {
			printf("%d", i);
		}
		printf("0");
		g++;
	}
	printf("\n");
}

void gamePlay(struct PlayerInfo* player) {
	switch (result) {
	case '!':
		player.lives--;
		player.moves--;
		break;
	case '$':
		player.treasure++;
		player.moves--;
		break;
	case '&':
		player.lives--;
		player.treasure++;
		player.moves--;
		break;
	case '.':
		player.moves--;
	default:
		break;
	}
}

void playing(void) {
	if (walk != 0) {
		for (int i = 0; i < historyCount - 1; i++) {
			if (history[i] == walk) {
				printf("===============> Dope! You've been here before!");
				break;
			}
		}
	}
	else {
		switch (result) {
		case '!':
			printf("===============> [!] !!! BOOOOOM !!! [!]\n");
			break;
		case '$':
			printf("===============> [$] $$$ Found Treasure! $$$ [$]\n");
			break;
		case '&':
			printf("===============> [&] !!! BOOOOOM !!! [&]\n");
			printf("===============> [&] $$$ Life Insurance Payout!!! [&]\n");
			break;
		case '.':
			printf("===============> [.] ...Nothing found here... [.]\n");
			break;
		default:
			break;
		}
	}
	
}
