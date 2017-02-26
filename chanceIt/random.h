/*Preconditions: N/A
Postconditions: random number generator has been seeded, generateNum may be called */
void random_init();

/*Preconditions; die exists and calls for a random number, a seed has been generated for the random number.
Postconditions; random number is returned to the die */
int generateNum(int max, int min);