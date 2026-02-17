#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include "player.h"
class Board {
public:
    Board() : board(3, vector<char>(3, ' ')) {}
    void displayBoard() const;
    bool makeMove(int row, int col, char symbol);
    bool checkWin(char symbol) const;
    bool isFull() const;    
private:    vector<vector<char>> board;
};  
#endif // BOARD_H