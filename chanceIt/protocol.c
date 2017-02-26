#include<stdio.h>
#include<string.h>
#include "socket.h"
#include "protocol.h"


int protocolInit(){
	socketInit();
	//char response[256], opponent[256];
	if (sendStr("HELLO: jared\n") <1) return 0;
	char response[1024], opponent[256];
	bzero(response, strlen(response));
	if (readLine(response) < 1) { // "get IS IT ME YOU'RE LOOKIN FOR?\n"
		puts(" check response error, quit.");
		return 0;
	}
	/*if (getResponse(response) < 1) { // get "Opponent: %s"
		puts("response error, quit.");
		return 0;
	}
	if (findOpponent(response, opponent) < 1) {
		puts("opponent error, quit.");
		return 0;
	}*/
	if (getOpponent( opponent) < 1) {
		puts("opponent error, quit.");
		return 0;
	}
	printf("your opponent is %s\n", opponent);
	
	if (readLine(response) < 1) { // get "Your roll was: %d. Opponent roll was: %d..."
		puts("response error, quit.");
		return 0;
	}
}

int isGameOver(char* response){
	if(strncmp(response, "You Win!", 8)==0 || strncmp(response, "You Lose", 8) == 0) return 1;
	return 0;
}

int getOpponent(char* opp){ 
	char reply[200];
	int bytes = readLine(reply);
	puts(reply);
	if(bytes>0) return sscanf(reply, "Opponent: %s\n", opp);
	return 0;
}

int findOpponent(char* response, char* opponent){
	if(response>0) return sscanf(response, "Opponent: %s\n", opponent);
	return 0;
}

int findRoll(char* response, int* roll1, int* roll2){
	if(response>0) return sscanf(response, " You Rolled: [%d,%d]", roll1, roll2);
	return 0;
}

int findScore(char* response, int* score){
	if(response>0) return sscanf(response, "Running Turn Score: %d\n", score);
	return 0;
}
int findTurn(char* response, int* turn){
	if(response>0) return sscanf(response, "Turn#: %d\n", turn);
	return 0;
}
int findRollNum(char* response, int* rollNum){
	if(response>0) return sscanf(response, "Roll#: %d\n", rollNum);
	return 0;
}
int findTotalScore(char* response, int* myTotal, int* opponentTotal){
	if(response>0) return sscanf(response, "Turn Starting Score: %d-%d\n", myTotal, opponentTotal);
	return 0;
}

int sendString(char* message){
	if( sendStr(message) < 0)
        return 0;
    return 1;
}