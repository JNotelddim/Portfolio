typedef struct Player{
	char* playerType;
	char* username;
	int score;
} Player;

/*Preconditions: player has been created
  Postconditions: player's type is assigned*/
void playerInit(Player* player, char* playerType, char* username);

/*Preconditions: game_init() and begin() have been called
  Postconditions: calls respective play round function for the type of player
  Returns: the integer result of the round*/
int playRound(Player* player);