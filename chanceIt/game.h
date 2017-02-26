typedef struct Game{
    char* mode;
    Player p1, p2;
	//Dice d;
}Game; 
/*Preconditions: N/A
Postconditions: game’s variables are instantiates and ‘objects’ like number
generator and sockets are created*/
void game_init(Game* g, char* mode, char* usernameP1, char* usernameP2);

/*Preconditions: game_init must have been called
Postconditions: the rounds of the game begin (looping through turns)*/
void begin(Game* g);
