#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "random.h"

int main(int argc, char* argv[]){
	random_init();
        int n = 0;
        for (n = 0; n < 15; n++)
        {
		int x = generateNum(atoi(argv[1]),atoi(argv[2]));	
		printf("%d\n", x);
	}
	return 0;
}
