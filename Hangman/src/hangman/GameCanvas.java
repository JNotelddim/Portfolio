/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package hangman;
import java.awt.*;
/**
 * this file contains the definition of a game canvas
 * @date March 16th, 2016
 * @author Jared Middleton
 */
public class GameCanvas extends Canvas{
    
    private int width, height;
    private HMGame game;
    private Font font = new Font("SANS_SERIF", Font.PLAIN, 25);
    
    /**
     * GameCanvas constructor which takes in a game and sets the canvas' game
     * @param game 
     */
    public GameCanvas(HMGame game){
        this.game = game;
    }
    
    /**
     * paint override, creates a black background, draws the gallows, the 
     * substitute guessing word, and any wrong guesses
     * @param g 
     */
    public void paint(Graphics g){
        g.setColor(new Color(26, 102, 255));
        g.fillRect(0, 0, this.getWidth(), this.getHeight());
        g.setColor(new Color(51,102,0));
        g.fillRect(0, this.getWidth()/2, this.getWidth(), this.getHeight());
        g.setColor(Color.WHITE);
        drawScore(g);
        g.setColor(new Color(102, 51, 0));
        drawGallows(g);
        g.setColor(Color.WHITE);
        drawGuesserWord(g);
        g.setFont(font);
        drawWrongGuesses(g);
        if(game.getWinState()) drawWin(g);
        
        switch(game.getNumWrong()){
            case 6:
                drawLoss(g);
                drawLeftLeg(g);
            case 5:
                drawRightLeg(g);
            case 4:
                drawLeftArm(g);
            case 3:
                drawRightArm(g);
            case 2:
                drawTorso(g);
            case 1:
                drawHead(g);
            default:
                break;
        }
    }
    
    /**
     * draw the score on the canvas
     * @param g 
     */
    public void drawScore(Graphics g){
        g.drawString(game.getWins() + "-" + game.getLosses(), 375, 50);
    }
    
    /**
     * announce that they won
     * @param g 
     */
    public void drawWin(Graphics g){
        g.drawString("YOU WIN! :D ", 230, 280);
    }
    
    /**
     * announce that they lost, and reveal the word
     * @param g 
     */
    public void drawLoss(Graphics g){
        g.drawString(":( you lose", 230, 280);
        g.drawString("The word was: " + game.getCurrentWord(), 230, 310);
    }
    /**
     * drawGallows draws the gallows on the canvas
     * @param g 
     */
    public void drawGallows(Graphics g){
        
        g.drawRect(35, 250, 125, 45); //base
        g.drawRect(55, 75, 10, 175); // pole
        g.drawRect(55, 65, 60, 10); // top
        g.setColor(new Color(153,102,51));
        g.fillRect(36, 251, 124, 44);
        g.fillRect(56, 76, 9, 174);
        g.fillRect(56, 66, 59, 9);
        g.setColor(new Color(102, 51, 0));
        for(int j=0; j<16; j++){
            g.drawLine(57, 83+j*10, 63, 89+j*10);
        }
        for(int j=0; j<6; j++){
            g.drawLine(57+j*10, 73, 66+j*10, 66);
        }
        g.drawLine(38, 270, 53, 254);
        for(int j=0; j<4; j++){
            g.drawLine(38+j*25, 287, 68+j*25, 254);
        }
        g.drawLine(138, 286, 153, 270);
        
        //nooseyness:
        g.setColor(new Color(255,255,153));
        g.drawLine(110,75, 110, 95);
        g.drawLine(108, 84, 110, 84);
        g.drawLine(108, 84, 112, 88);
        g.drawLine(108, 87, 112, 91);
        g.drawLine(108, 90, 112, 94);
        g.drawLine(110, 94, 112, 94);
    }
    /**
     * draGuesserWord draws the substitute word which they're guessing at
     * @param g 
     */
    public void drawGuesserWord(Graphics g){
        g.setFont(new Font("SANS_SERIF", Font.PLAIN, 29));
        g.drawString(game.getSubstitute(), 230,150);
    }
    /**
     * drawWrongGuesses draws the array of chars which are incorrect guesses
     * @param g 
     */
    public void drawWrongGuesses(Graphics g){
        String str = new String(game.getWrongGuesses());
        g.drawString(str, 75,400);
    }
    /**
     * drawLeftLeg draws the left leg of the dude
     * @param g 
     */
    public void drawLeftLeg(Graphics g){
        g.drawLine(110,160,100,190);
    }
    /**
     * drawRightLeg draws the right leg of the dude
     * @param g 
     */
    public void drawRightLeg(Graphics g){
        g.drawLine(110,160,120,190);
    }
    /**
     * drawTorse draws the torso of the dude
     * @param g 
     */
    public void drawTorso(Graphics g){
        g.drawLine(110,120,110,160);
    }
    /**
     * drawLeftArm draws the left arm of the dude
     * @param g 
     */
    public void drawLeftArm(Graphics g){
        g.drawLine(110,130,90,150);
    }
    /**
     * drawRightArm draws the right arm of the dude
     * @param g 
     */
    public void drawRightArm(Graphics g){
        g.drawLine(110,130,130,150);
    }
    /**
     * drawHead draws the head of the dude
     * @param g 
     */
    public void drawHead(Graphics g){
        g.drawOval(97,95,25,25);
        g.drawLine(102, 105, 108, 105);
        g.drawLine(112, 105, 118, 105);
    }
}
