#ifndef PLAYER_H
#define PLAYER_H


class Player {
public:
    Player(char symbol) : symbol(symbol) {}
    char getSymbol() const { return symbol; }
private:
    char symbol;
};      

#endif // PLAYER_H