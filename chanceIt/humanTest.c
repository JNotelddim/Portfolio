#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "dice.h"
#include "random.h"
#include "humanPlayer.h"

int main(int argc, char* argv[]){
	int score = humanPlayRound("username");
	printf("%d\n", score);
}