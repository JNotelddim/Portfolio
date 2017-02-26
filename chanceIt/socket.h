/*preconditions: a socket has been declared
  postconditions: the socket has connected to the host on a certain port*/
int socketInit();

/*send(str) sends a char array to the server via the socket, using write
Preconditions: socket has been created
Postconditions: data packet is sent to server*/
int sendStr(char* message);

/*uses read()
Preconditions: socket has been created, data has been sent from the server
Postconditions: returns string which is received from server
returns: a string which has been received from the server*/
int recvStr(char* response);

int readLine (char* lineBuffer);