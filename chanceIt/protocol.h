/*send(str) sends a char array to the server via the socket, using write
Preconditions: socket has been created
Postconditions: data packet is sent to server*/
int getOpponent(char* opp);

/*uses read()
Preconditions: socket has been created, data has been sent from the server
Postconditions: returns string which is received from server
returns: a string which has been received from the server*/
int isGameOver(char* response);

int protocolInit();

int getResponse(char* response);

int findRoll(char* response, int* roll1, int* roll2);

int findScore(char* response, int* score);