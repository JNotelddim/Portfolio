#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "player.h"
#include "game.h"

int main(int argc, char* argv[]){
	Game g;
	char* mode = argv[1];
	char* p1name = argv[2];
	char* p2name = argv[3];
	
	game_init(&g, mode, p1name, p2name);
	
	begin(&g);
	return 0;
}