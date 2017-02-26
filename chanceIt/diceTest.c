#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "dice.h"
#include "random.h"

int main(int argc, char* argv[]){
	int i;
	init_dice();
	
	printf("regular Player val test");
    for(i = 0; i < 6; i++){
			sleep(.1);
			printf("test %d\n", i);
			int roll1 = roll();
			int roll2 = roll();
			int val = roll1+roll2;
			printf("%d\n", val);
	}
	printf("regular AI val test");
    for(i = 0; i < 6; i++){
			printf("test %d\n", i);
			int roll1 = roll();
			int roll2 = roll();
			int val = roll1+roll2;
			printf("%d\n", val);
	}
	printf("Robustness test");
	int x = 0;
	int y = 12;
	for(i = 0; i <= 50000; i++){
		int roll1 = roll();
		int roll2 = roll();
		int val = roll1+roll2;
		if (val > x){
			x = val;
		}
		if (val < y){
			y = val;
		}
		printf("%d\n", val);
	}
	printf("max is %d\n", x);
	printf("min is %d\n", y);
}