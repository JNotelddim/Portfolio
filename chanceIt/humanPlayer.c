#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "humanPlayer.h"
#include "dice.h"

/*pre: Human Player has been initialized
post: Player played round
returns: total round score*/
int humanPlayRound(char* playerUsername){
	fflush(stdin); // clear input buffer
    int point = 0;
    int score = 0;
	int cont = 1;
	int roll1, roll2, sum;
	char input = ' ';
	//init_dice();
	printf("\t\t%s's turn:\n", playerUsername);
	printf("\t______________________________________\n");
	
	roll1 = roll();
    roll2 = roll();
    point = roll1+roll2;
    score = point;
	sum = point;
	printf("\t\t**  ROLL: _%d_  (%d + %d)  **\n\t\t**  ROUND TOTAL: _%d_  **\n",  sum, roll1, roll2, score);
	printf("Would you like to reroll?\n");
	input = getchar();
	while(input != 'Y' && input != 'N' && input != 'y' && input != 'n'){
		printf("Y / N \n");
        input = getchar();
	}
	if (input == 'N' || input == 'n'){
	    cont = 0;
	}
	while (cont != 0){
		roll1 = roll();
        roll2 = roll();
        sum = roll1 + roll2;
        if (sum == point){
			printf("\t\t**  ROLL: _%d_  (%d + %d)  **\n\t\t**  ROUND TOTAL: _%d_  **\n",  sum, roll1, roll2, score);
            printf("Sorry, you rolled your first roll again: %d! You lose the round.\n\n", point);
            cont = 0;
            score = 0;
            continue;
        }
        score += sum;
		printf("\t\t**  ROLL: _%d_  (%d + %d)  **\n\t\t**  ROUND TOTAL: _%d_  **\n",  sum, roll1, roll2, score);
		printf("Would you like to reroll?\n");
		fflush(stdin); // clear input buffer
		input = getchar();
		while(input != 'Y' && input != 'N' && input != 'y' && input != 'n'){
			fflush(stdin); // clear input buffer
			printf("Y / N \n");
			input = getchar();
		}
		if (input == 'N' || input == 'n'){
		    cont = 0;
		}
	}
	//printf("Score for the round: %u\n", score);
	return score;
}
