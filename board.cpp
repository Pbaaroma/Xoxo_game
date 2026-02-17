/**
 * @file board.cpp
 * @author Gabriel Kofi Coffie Boafo & Emmanuel Mensah 
 * @date 02-17-2026
 * @brief This file contains the implementation of the Board class
 */

#include<iostream>
#include "board.h"

  // The Constructor.
  Board::Board() : grid(3, std::vector<char>(3, ' ')), size(3) {}
   
  // Display the board function
  void Board ::displayBoard() const{

    std:: cout << "\nTIC TAC TOE:\n";
    // Loop through the grid and display the board
    for(int i =0; i< size; i++){
        for (int j =0; j< size; j++){
            std:: cout << grid[i][j] << " ";
// Display the vertical line between columns
            if (j < size -1){
                std:: cout << "| ";
            }
        }
        std:: cout << std:: endl;
// Display the horizontal line between rows
        if (i <size -1) {
            for(int k =0; k< size; k++){
                std:: cout << "--";
                if (k < size -1){
                    std:: cout << "+ ";
                }
            }
            std:: cout << std:: endl;
        }
  }

  std:: cout << std:: endl;
    }   
    // Make move function
    bool Board::makeMove(int row, int col, char symbol){
        if (row >=0 && row < size && col >=0 && col < size && grid[row][col] == ' '){
            grid[row][col] = symbol;
            return true;
        }
        return false;
    }
    // Check win function
    bool Board::checkWin(char symbol) const{
        // Check rows
        for (int i =0; i< size; i++){
            bool win = true;
            for (int j =0; j< size; j++){
                if (grid[i][j] != symbol){
                    win = false;
                    break;
                }
            }
            if (win){
                return true;
            }
        }
        // Check columns
        for (int j =0; j< size; j++){
            bool win = true;
            for (int i =0; i< size; i++){
                if (grid[i][j] != symbol){
                    win = false;
                    break;
                }
            }
            if (win){
                return true;
            }
        }
        // Check diagonals
        bool win = true;
        for (int i =0; i< size; i++){
            if (grid[i][i] != symbol){
                win = false;
                break;
            }
        }
        if (win){
            return true;
        }
        win = true;
        for (int i =0; i< size; i++){
            if (grid[i][size -1 -i] != symbol){
                win = false;
                break;
            }
        }
        return win;
    }
    // Check if the board is full
    bool Board ::isFull() const{
        for (int i =0; i< size; i++){
            for (int j =0; j< size; j++){
                if (grid[i][j] == ' '){
                    return false;
                }
            }
        }
        return true;
    }
    // reset the board function
    void Board::resetBoard(){   
        for (int i =0; i< size; i++){
            for (int j =0; j< size; j++){
                grid[i][j] = ' ';
            }
        }
    }