/**
 * @file main.cpp
 * @author Gabriel Kofi Coffie Boafo & Emmanuel Mensah
 * @date 02-18-2026
 * @brief The main function of the tic-tac-toe game. It creates the players and the board, and starts the game loop
 */

#include <iostream>
#include <cstdlib>
#include <thread>
#include <mutex>
#include <atomic>
#include <chrono>

#include "board.h"
#include "player.h"

using namespace std;

// Thread function for a player
void playGame(Player player, Board &board, std::mutex &m, std::atomic<bool> &gameOver) {
    while (!gameOver) {
        int row, col;
        bool moveMade = false;

        // Try random moves until successful
        do {
            row = std::rand() % 3;
            col = std::rand() % 3;

            //  lock mutex
            std::lock_guard<std::mutex> lock(m);

            if (gameOver) break; // check again inside lock

            moveMade = board.makeMove(row, col, player.getSymbol());

            if (moveMade) {
                board.displayBoard();

                // this make the game slower and more readable for me to see the moves being made by the players.
    std::this_thread::sleep_for(std::chrono::seconds(2));

                // Check for winner
                if (board.checkWin(player.getSymbol())) {
                    std::cout << "Congratulations! " << player.getName() << " wins!" << std::endl;
                    gameOver = true;
                } else if (board.isFull()) {
                    std::cout << "It's a draw!" << std::endl;
                    gameOver = true;
                }
            }

        } while (!moveMade);

        // small delay for readability
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // seed random generator

    // Create players
    Player player1('X', "Player 1");
    Player player2('O', "Player 2");

    // Create the game board
    Board board;

    // Display initial empty board
    board.displayBoard();

    // Shared data for threads
    std::mutex boardMutex;
    std::atomic<bool> gameOver(false);

    // Launch threads for Player X and Player O
    std::thread threadX(playGame, player1, std::ref(board), std::ref(boardMutex), std::ref(gameOver));
    std::thread threadO(playGame, player2, std::ref(board), std::ref(boardMutex), std::ref(gameOver));

    // Wait for both threads to finish
    threadX.join();
    threadO.join();

    return 0;
}
