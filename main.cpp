/**
 * @file main.cpp
 * @author Gabriel Kofi Coffie Boafo & Emmanuel Mensah
 * @brief This is the main file for the project. It contains the main function which is
 */

#include<iostream>
using namespace std;
#include "board.h"
#include "player.h"

int main(){
    // Create the two players
    Player player1('X', "Player 1");
    Player player2('O', "Player 2");

    // Create the game board
    Board board;

    //Display the empty board 
    board.displayBoard();
    return 0;
}