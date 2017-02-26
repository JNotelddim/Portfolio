/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package hangman;

import javax.swing.JFrame;
import java.awt.Dimension;

/**
 * this is the driver file
 * @date March 16th, 2016
 * @author Jared Middleton
 */
public class Hangman {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        boolean run = true, cont = true;
        final int SIZE = 500;
        JFrame frame = new JFrame();
        
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(SIZE, SIZE);
        //create the game and add it to the canvas
        HMGame game = new HMGame();
        GameCanvas canvas = new GameCanvas(game);
        
        //print the rules
        run = game.printRules(); // if the person chooses to play it'll return true
        //while the person wants to keep playing, 
        while(cont && run){
            game.setup(canvas);
            frame.getContentPane().add(canvas);
            frame.setMinimumSize(new Dimension(SIZE, SIZE));
            frame.pack();
            frame.setVisible(true);
            cont = game.runGuesses();
        }
        System.exit(0);
    }
}
