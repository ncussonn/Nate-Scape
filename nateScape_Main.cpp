using namespace std;

// import various necessary libraries

#include <iostream>         // cout cin
#include <stdio.h>          // standard input/output library
#include <unistd.h>         // sleep library
#include "mainLibrary.h"    // main functions and classes for game aspects
#include "combatLibrary.h"  // functions and classes for combat related events

// How to create the .exe
/* g++ nateScape_Main.cpp -o textGame -static*/

int main() {   
    
    cout << "Welcome to Nate-Scape!\n"<< endl;

    // Create an object called game
    Game game;

    // initialize attributes of player (gender and name)
    game.player.initialize();    

    // provide the rules
    game.printRules();

    // remain in this loop until the game is won
    while(game.win_flag != 1) {
        
        // print turn number
        game.printTurn();

        // poll the player for an action
        game.setAction();

        // perform the action
        game.act(player.getRoom());

        // increment the turn count
        game.incrementTurn(1);

        // for testing
        if(game.getTurn() == 5) {

            // set the game to won on turn 5
            game.win_flag = 1;

        }

        // check if game won
        game.checkWin();

    }    

    // exiting while loop implies game has been won
    cout << "Congratulations! You reached the exit!";

    sleep(15); // wait 15 seconds for player to see game completed

    return 0;
}
