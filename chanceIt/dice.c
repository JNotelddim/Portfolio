#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dice.h"
#include "random.h"
#define NUM_SIDES 6
#define MIN 1

/*preconditions: N/A
 *postconditions: a die has been created */
void init_dice()
{
	random_init();
}

/*preconditions: a die must exist, a random number generator has been initialized
 *postconditions: N/a
 *returns: result of the roll*/
int roll(){
	int roll = generateNum(NUM_SIDES, MIN);
	return roll;
}

