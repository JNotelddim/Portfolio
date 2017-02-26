#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "socket.h"
#include "protocol.h"
#include "networkPlayer.h"

static char response[1024], opponent[256], message[10];
static int origRoll, roll1, roll2, turnScore, lostRound=0, first=1, turn, rollNum;

int networkPlayRound(){	
	puts("_____________________");
	if (readLine(response) < 1) { // Turn Starting Score: X-X
		puts("Error getting response.\n");
		return -1;
	}puts(response);
	
	
	
	if(isGameOver(response) != 0) return 1; // returns if game is over
	
	if (readLine(response) < 1) { // Turn#: X
		puts("Error getting turn #.\n");
		return -1;
	}puts(response);
	if (findTurn(response, &turn) < 1) {
		puts("Error parsing for turn.\n");
		return -1;
	}
	
	
	if (readLine(response) < 1) { // Roll#: X
		puts("Error getting roll #.\n");
		return -1;
	}puts(response);
	if (findRollNum(response, &rollNum) < 1) {
		puts("Error parsing for roll num.\n");
		return -1;
	}
	
	
	if (readLine(response) < 1) { // You Rolled: [X,X]
		puts("Error getting roll result.\n");
		return -1;
	}puts(response);
	if (findRoll(response, &roll1, &roll2) < 1) {
		puts("Error parsing for roll.");
		printf("%d, %d\n", roll1, roll2);
		return -1;
	}
	//**** Set lost round if  rollSum == origRoll && 
	if(rollNum == 1 && first == 1){ //
		puts("first roll");
		origRoll = roll1 + roll2; // get value of first roll
		lostRound = 0;
		first = 0;
	} else { 	// check if you reroll the first roll
		puts("not first roll");
		if ((roll1+roll2) == origRoll){ // && rollNum != 1
			printf("%d + %d == %d\n", roll1, roll2, origRoll);
			lostRound = 1;
			first = 1;
		}
	}
	
	if (readLine(response) < 1) { // Running Turn Score: X-X
		puts("Error getting turn score.\n");
		return -1;
	}puts(response);
	if (findScore(response, &turnScore) < 1) {
		puts("Error parsing for score.\n");
		return -1;
	}
	
	if (readLine(response) < 1) { // --
		puts("Error getting --.\n");
		return -1;
	}puts(response);
	
	printf("turn#:%d, origRoll:%d, rollnum:%d, die1: %d, die2:%d,  turnScore:%d [%d]\n", 
	turn, origRoll, rollNum, roll1, roll2, turnScore, lostRound);
	if ( lostRound != 1 && first == 0) {
		if (readLine(response) < 1) { // chance-it? [Y/n]
			puts("Error getting chance-it Y/n prompt.\n");
			return -1;
		}puts(response);
		(rollNum < 9 ) ? strcpy(message, "Y\n") : strcpy(message, "n\n"); // send Y if rollNum is less than 5
		printf("send %s", message);
		if( sendString(message) < 0){
			puts("Send failed");
			return 1;
		}
	}
	return 0;
}