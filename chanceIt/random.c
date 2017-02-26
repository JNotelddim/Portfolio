#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "random.h"
int generateNum(int max, int min)
{
	int delta = max - min;
	int num = (rand() % (delta+1) + min);
	return num;
}
void random_init(){
	srand(time(NULL));
}
