#include <stdio.h>
#include <stdlib.h>
#include "userInterface.h"


/*preconditions: table_init() has been called
  postconditions: N/A
  returns: ASCII string representation of rules*/
char* showRules(){
	return "\n\n\t\tGAME RULES\n\t\t___________\nFor the game of ChanceIt, 2 players are required.\nEach player can either be a computer player or a human.\nThe object of the game is to be the player with the highest score\n after completing 20 rounds of play.\nAt the beginnning of the game, each player rolls a die: high goes first.\nDuring each round, each player takes a turn.\nA player's total score is the sum of their turn scores.\nThe sum of 2 six sided dice for each roll is taken as the amount for that roll.\nThe first roll of each turn is to be remembered as the 'First Roll'.\nEach subsequent roll is added to the player's round total.\nIf a player decided to stop, then their turn ends and their score\n for that turn is the sum of all rolls during that turn.\nIf the player decides to continue, they roll the dice again.\nIf in re-rolling the dice, a player's roll sum matches the first roll sum, then their turn ends and their score for that turn is 0.\n\n";
}




/*
return "For the game of chance-it, 2 players are required. Each player can either be a computer player or a human.\nThe object of the game is to be the player with the highest score after completing 20 rounds of play. \nAt the beginning of the game, each player rolls a die:  high goes first.\nDuring each round, each player takes a turn .  A player’s total score is the sum of their turn scores. \nThe the sum of 2 six sided die for each roll is taken as the amount for that roll. \nThe first roll of each turn is to be remembered as the First Roll.\nEach subsequent roll is added to the players round total.\nIf a player decides to stop, then their turn ends and their score for that turn is the sum of all rolls during that turn;\nif the player decides to continue, they roll the dice again.\nIf in re-rolling the dice, a player's roll sum matches their first roll sum, then their turn ends and their score for that turn is zero.";
*/