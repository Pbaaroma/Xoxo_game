/**
 * @file main.cpp
 * @author Gabriel Kofi Coffie Boafo & Emmanuel Mensah
 * @brief This is the main file for the project. It contains the main function which is
 */

#include<iostream>
#include<cstdlib>
using namespace std;
#include "board.h"
#include "player.h"

int main(){

    //seed the random number generator
    srand(static_cast<unsigned int>(time(0)));

    // Create the two players
    Player player1('X', "Player 1");
    Player player2('O', "Player 2");

    // Create the game board
    Board board;
  
   // Display the empty board 
    board.displayBoard();
    

    //while loop to keep the game running until there is a winner or a draw
    bool xTurn = true;
bool gameOver = false;

while (!gameOver) {
    int row, col;
    bool makeMove = false;

    // try until a valid move is made
    do {
        row = std::rand() % 3; // remove 'int' here
        col = std::rand() % 3;

        if (xTurn)
            makeMove = board.makeMove(row, col, player1.getSymbol());
        else
            makeMove = board.makeMove(row, col, player2.getSymbol());
    } while (!makeMove);

    // Display the board after each move
    board.displayBoard();

    // Check for winner
   if (board.checkWin(player1.getSymbol())) {
    cout << "Congratulations! " << player1.getName() << " wins!" << endl;
    gameOver = true;
} 
else if (board.checkWin(player2.getSymbol())) {
    cout << "Congratulations! " << player2.getName() << " wins!" << endl;
    gameOver = true;
} 
else if (board.isFull()) {
    cout << "It's a draw!" << endl;
    gameOver = true;
}
}
return 0;
}