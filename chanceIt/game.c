#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dice.h"
#include "userInterface.h"
#include "player.h"
#include "game.h"
#define NUM_ROUNDS 4

void game_init(Game* g, char* mode, char* usernameP1, char* usernameP2){
    g->mode = mode;
    if (strcmp(mode,"-2p")==0){//TWO PLAYER
		init_dice();
		int p1Roll = roll();
		int p2Roll = roll();
		printf("%s\n", showRules());
		printf("%s's roll: %d, %s's roll: %d\n", usernameP1, p1Roll, usernameP2, p2Roll);
		
		if(p1Roll > p2Roll){
			printf("%s gets the first turn!\n\n", usernameP1);
			playerInit(&g->p1, "humanPlayer", usernameP1);
			playerInit(&g->p2, "humanPlayer", usernameP2);
		} else if (p1Roll < p2Roll){
			printf("%s gets the first turn!\n\n", usernameP2);
			playerInit(&g->p1, "humanPlayer", usernameP2);
			playerInit(&g->p2, "humanPlayer", usernameP1);
		} else {
			while (p1Roll == p2Roll){
				p1Roll = roll();
				p2Roll = roll();
			}
			if(p1Roll > p2Roll){
				printf("REROLL! %s's roll: %d, %s's roll: %d\n", usernameP1, p1Roll, usernameP2, p2Roll);
				printf("%s gets the first turn!\n\n", usernameP1);
				playerInit(&g->p1, "humanPlayer", usernameP1);
				playerInit(&g->p2, "humanPlayer", usernameP2);
			} else if (p1Roll < p2Roll){
				printf("REROLL! %s's roll: %d, %s's roll: %d\n", usernameP1, p1Roll, usernameP2, p2Roll);
				printf("%s gets the first turn!\n\n", usernameP2);
				playerInit(&g->p1, "humanPlayer", usernameP2);
				playerInit(&g->p2, "humanPlayer", usernameP1);
			}
		}
		
    } else if(strcmp(mode,"-1p")==0){ // 1P VS AI
		puts("Sorry, that game mode is not supported.");
		
	} else if(strcmp(mode,"-cvn")==0){ // 1P VS AI
		playerInit(&g->p1, "networkPlayer", usernameP1);
		
	}else { // Not a valid game mode
		puts("Sorry, that game mode is not supported.");
	}
}

void begin(Game* g){
    int round = 0;
	puts("Game begin");
	if (strcmp(g->mode, "-2p") == 0){ //2P
		while (round < NUM_ROUNDS){
			printf("\n\n\nRound %d: \t", round+1);
			printf("%s: %d, %s: %d\n", g->p1.username, g->p1.score, g->p2.username, g->p2.score);
			g->p1.score += playRound(&g->p1);
			
			printf("\n\n\nRound %d:\t", round+1);
			printf("%s: %d, %s: %d\n", g->p1.username, g->p1.score, g->p2.username, g->p2.score);
			g->p2.score += playRound(&g->p2);
			round++;
		}
		if(g->p1.score > g->p2.score){
			printf("%s Wins!\n%s's score: %d\n%s's score: %d\n", g->p1.username, g->p1.username, g->p1.score, g->p2.username, g->p2.score);
		} else if (g->p2.score > g->p1.score){
			printf("%s Wins!\n%s's score: %d\n%s's score: %d\n", g->p2.username, g->p1.username, g->p1.score, g->p2.username, g->p2.score);
		} else {
			printf("Game over, looks like a tie!\n%s's score: %d\n%s's score: %d\n", g->p1.username, g->p1.score, g->p2.username, g->p2.score);
		}
    } else if (strcmp(g->mode,"-cvn")==0){ // AI VS NETWORK
		while(playRound(&g->p1) == 0);
		/*while (round < NUM_ROUNDS){
			printf("\n\n\nRound %d: \t", round+1);
			printf("%s: %d, %s: %d\n", g->p1.username, g->p1.score, g->p2.username, g->p2.score);
			//g->p1.score += playRound(&g->p1);
			round++;
		}*/
	}
    /*
	if(g->p1.score > g->p2.score){
		printf("%s Wins!\n%s's score: %d\n%s's score: %d\n", g->p1.username, g->p1.username, g->p1.score, g->p2.username, g->p2.score);
	} else if (g->p2.score > g->p1.score){
		printf("%s Wins!\n%s's score: %d\n%s's score: %d\n", g->p2.username, g->p1.username, g->p1.score, g->p2.username, g->p2.score);
	} else {
		printf("Game over, looks like a tie!\n%s's score: %d\n%s's score: %d\n", g->p1.username, g->p1.score, g->p2.username, g->p2.score);
	}*/
}