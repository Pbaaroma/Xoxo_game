/**
 * @file player.cpp
 * @author Gabriel Kofi Coffie Boafo & Emmanuel Mensah
 * @date  02-16-2026
 * @brief This file contains the implementation of the Player class which represents a player in the game.
 */


#include <iostream>
#include "player.h"

 // Default construor
Player::Player() : symbol('X'), name("player") {}

// Constructor with parameters
Player::Player(char symbol, const std::string& name) : symbol(symbol), name(name) {}


// setter for the player's name
void Player::setName(const std::string& playerName) {
    name = playerName;
}

// setter for the player's symbol
void Player::setSymbol(char playerSymbol) {
    symbol = playerSymbol;
}

// getter for the player's name
const std::string& Player::getName() const {
    return name;
}

// getter for the player's symbol
char Player::getSymbol() const {
    return symbol;
}


