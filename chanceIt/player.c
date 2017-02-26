#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "socket.h"
#include "humanPlayer.h"
#include "networkPlayer.h"
#include "player.h"

/*Preconditions: player has been created
  Postconditions: player's type is assigned*/
void playerInit(Player* player, char* playerType, char* username){
	player->playerType = playerType;
	player->username = username;
	player->score = 0;
	if(strcmp(playerType, "networkPlayer") == 0) protocolInit();
}

/*Preconditions: game_init() and begin() have been called
  Postconditions: calls respective play round function for the type of player
  Returns: the integer result of the round*/
int playRound(Player* player){
	if (strcmp(player->playerType, "humanPlayer") == 0 ){
		return humanPlayRound(player->username);
	}
	if (strcmp(player->playerType, "networkPlayer") == 0 ){
		return networkPlayRound();
	}
	if (strcmp(player->playerType, "AIPlayer") == 0 ){
		//return AIPlayRound();
		return 0;
	}
}