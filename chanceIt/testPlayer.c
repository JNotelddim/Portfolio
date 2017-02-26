#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "player.h"
#include "humanPlayer.h"

int main(int argc, char* argv[]){
	//struct Player p;
	//playerInit(p, "humanPlayer");
	int round = playRound("humanPlayer", "Jared");
	printf("Score for the round: %u\n", round);
	return 0;
}