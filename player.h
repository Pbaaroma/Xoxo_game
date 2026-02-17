/**
 * @file player.h
 * @author Gabriel Kofi Coffie Boafo & Emmanuel Mensah
 * @brief This file contains the definition of the Player class which represents a player in the game.
 */

#ifndef PLAYER_H
#define PLAYER_H
#include <string>

class Player {
    private:
        std::string name; // Player's name
    char symbol; // X or O 


public:

// constructor for the Player class. It takes a symbol and a name as parameters and initializes the player's symbol and name.
    Player(); // Default constructor
    
    // Parameterized constructor

    Player(char symbol, const std::string& name);
    // Getters for the player's name and symbol
    char getSymbol() const;
    const std::string& getName() const;

    // Setter for the player's name
    void setName(const std::string& playerName);
    void setSymbol(char playerSymbol);
    
};      

#endif // PLAYER_H