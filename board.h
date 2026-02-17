/**
 * @file board.h
 * @author Gabriel Kofi Coffie Boafo & Emmanuel Mensah
 * @date  02-16-2026
 * @brief This file contains the definition of the Board class which represents the game board for the tic-tac-toe game.
 */

#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include "player.h"


class Board {
        private:
    std::vector<std::vector<char>> grid; // 3x3 board represented as a 2D vector
     int size; // Size of the board (3 for a 3x3 board)

public:
        // Constructor to initialize the board with empty spaces
    Board() ;

      // That is the displayBoard function.   
    void displayBoard() const;

        // This function is the function that allows a player to make a move on the board.    
    bool makeMove(int row, int col, char symbol);

      // This is to check everytime if a player has won the game 
    bool checkWin(char symbol) const;
    // This is to check if the board is full and there are no more moves left

    bool isFull() const;

    // Reset the board function 
    void resetBoard();
};  
#endif // BOARD_H   