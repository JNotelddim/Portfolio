/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package hangman;

import java.util.Scanner;
import javax.swing.JFrame;

/**
 * This file contains the definition of a hangman game
 * @date March 16th, 2016
 * @author Jared Middleton
 */
public class HMGame {
    private static final int MAX_LENGTH = 10;
    // int - how many games the user has played this session
    //private static int gameNum;
    private GameCanvas can;
    // string - current word
    private String currentWord, substitute;
    /* char arrays - letters they've guessed that were wrong, letters they've 
    guessed that were right, and letters which haven't been guessed yet */
    private char[] wrongGuesses = {' ',' ',' ',' ',' ',' '};
    private char[] rightGuesses;
    private int numWrong = 0;
    private boolean winner = false;
    private static int numWins = 0, numLosses = 0;
    private char[] notYetGuessed = {'a','b','c','d','e','f','g','h','i','j','k',
        'l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    private String[] words = {"cradle","mouse","alphabet","tree","couch","apple",
        "keys","pants","rubbish","knife","trumpet","board","green","choose","wire",
        "chord","super","loop","apply","leap","cool","strap","bore","side","pixel",
        "panel","take","flee","buzz","year","follow","sing","reap","user","make",
        "seer","free","cheap","djinn","tale","draw","gust","usurp","from","meal",
        "chore","broccoli","kale","room","leek","leak"};
    
    /**
     * constructor for HMGame.. doesn't do anything
     */
    public HMGame(){
        
    }
       
    /**
     * printRules displays rules and determines whether or not someone wants to play
     * @return whether or not they want to play
     */
    public boolean printRules(){
        Scanner scan = new Scanner(System.in);
        System.out.println("Welcome to hangman!\n" +
            "Rules of the game:\n" +
            "Your job is to try to find out the secret word, by guessing one letter at\n" + // describe rules of game
            "a time. But beware! If you incorrectly select a letter that is not in\n" +
            "the secret word, you will be one step closer to hanging on the gallows!\n" +
            "The secret word is made up of letters a-z.\n" +
            "Do you want to play? (y - yes, n - no)");
        String response = scan.nextLine().toLowerCase();
        if(response.equals("y") || response.equals("yes")){
            return true;
        } else{
        // if they said no:
            System.out.println("Okeydokey then, good bye.");
            return false;
        }
    }
    
    /**
     * setup clears previous wrong guesses, and gets a new word for guessing
     * @param can canvas
     */
    public void setup(GameCanvas can){
        this.can = can;
        numWrong = 0;
        wrongGuesses = clearWrong(wrongGuesses);
        Scanner scan = new Scanner(System.in);
            
        // create an instance of the game
        // -> creating a canvas and initializing the class variables
        System.out.println("Would you like to enter a word for someone else to guess? y - yes, n - no");
        String response = scan.nextLine().toLowerCase();
        if(response.equals("y") || response.equals("yes")){
            do{
            System.out.println("Please enter the word you would like for your friend to have to guess. (Max 10 characters)");
            this.currentWord = scan.nextLine();
            this.substitute = convertToHyphens(this.currentWord);
            } while (this.currentWord.length() > MAX_LENGTH || this.currentWord.length() < 1);
            for(int i = 0; i<50; i++){
                System.out.println();
            }
            this.can.repaint();
        } else {
            System.out.println("A word has been selected from the internal dictionary.");
            this.currentWord = words[(int)(Math.random()*(words.length-1))]; // need to add a dictionary
            this.substitute = convertToHyphens(this.currentWord);
            this.can.repaint();
        }
    }
    
    /**
     * runGuesses loop for prompting for next guess, 
     * and checking whether or not it's in the string
     * also checks whether or not person wants to keep playing
     * @return cont
     */
    public boolean runGuesses(){
        boolean done = false, cont = false, invalid=false;
        Scanner scan = new Scanner(System.in);
        String response;
        this.winner = false;
        while (!done){
            if(numWrong>=6){
                this.numLosses ++;
                System.out.println("Oh No! You lost! :( \nYou've won " + getWins() 
                            + " games and lost " + getLosses() + " games.\nWould you like to play again? (y/n)");
                response = scan.nextLine().toLowerCase();
                if(response.equals("y") || response.equals("yes")){
                        cont = true;
                } else {
                    cont = false;
                }
                break;
            }
            System.out.println("Word: " + this.substitute);
            System.out.println("What's your guess? - Please type in a letter.");
            response = scan.nextLine().toLowerCase();
            if(response.equals("")){
                invalid = true;
                while(invalid){
                    System.out.println("What's your guess? - Please type in a letter.");
                    response = scan.nextLine().toLowerCase();
                    if(response.length() > 0){
                        invalid = false;
                    }
                }
            }
            
            char letter = response.charAt(0);
            boolean isThere = letterSpot(this.currentWord, letter);
            if(!isThere){
                this.wrongGuesses[numWrong] = letter;
                System.out.println("The letter was not in the word!");
                numWrong += 1;
                can.repaint();
            } else {
                System.out.println("Good guess!");
                this.substitute = this.replaceSubstitute(this.currentWord, this.substitute, letter);
                if(this.substitute.equals(this.currentWord)){
                    this.winner = true;
                    this.numWins++;
                    can.repaint();
                    System.out.println("Congratulations! You win! The word was: " 
                            + this.substitute + ". You've won " + getWins() 
                            + " games and lost " + getLosses() + " games.");
                    done = true;
                    System.out.println("Would you like to play again? (y/n)");
                    response = scan.nextLine().toLowerCase();
                    if(response.equals("y") || response.equals("yes")){
                        cont = true;
                    } else {
                        cont = false;
                    }
                }
                can.repaint();
            }
        }
        return cont;
    }
    
        /**
     * convertToUScores changes a string to all hyphens
     * @param s string to copy
     * @return a string of equal length, but of all hyphens
     */
    public static String convertToHyphens(String s){
        StringBuilder builder = new StringBuilder();
        for (int i = 0; i<s.length(); i++){
            builder.append("-");
        }
        return builder.toString();
    }
    /**
     * remake the substitute string with the correctly guessed letter
     * @param letter, a letter which was guessed correctly
     * @return underscore string created with the correctly guessed letters in it
     */
    public String replaceSubstitute(String s, String s2, char letter){
        StringBuilder builder = new StringBuilder();
        for (int i = 0; i<s.length(); i++){
            if(s.charAt(i)==letter){
                builder.append(letter);
            } else {
                builder.append(s2.charAt(i));
            }
        }
        return builder.toString();
    }
    
    /**
     * letterSpot finds a letter in a string
     * @param s, the string to search through
     * @param letter the letter to look for
     * @return true or false
     */
    public boolean letterSpot(String s, char letter){
        for(int i = 0; i<s.length(); i++){
            if(s.charAt(i) == letter){
                return true;
            }
        }
        return false;
    }
    
    public int getNumWrong(){
        return numWrong;
    }
    /**
     * getSubstitute
     * @return substitute
     */
    public String getSubstitute(){
        return substitute;
    }
    /**
     * getCurrentWord
     * @return currentWord
     */
    public String getCurrentWord(){
        return currentWord;
    }
    /**
     * getWrongGuesses
     * @return wrongGuesses
     */
    public char[] getWrongGuesses(){
        return wrongGuesses;
    }
    /**
     * getWins 
     * @return number of wins
     */
    public int getWins(){
        return this.numWins;
    }
    /**
     * getLosses
     * @return number of losses
     */
    public int getLosses(){
        return this.numLosses;
    }
    /**
     * resets wrong guesses
     * @param prior array of previous wrong guesses
     * @return 
     */
    public char[] clearWrong(char[] prior){
        char[] cleared = new char[prior.length];
        for(int i = 0; i<prior.length-1; i++){
            cleared[i] = ' ';
        }
        return cleared;
    }
    /**
     * getWinState
     * @return whether or not the game has just been won
     */
    public boolean getWinState(){
        return this.winner;
    }
}
