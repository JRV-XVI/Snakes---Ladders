#ifndef PLAYER_H
#define PLAYER_H


class Player {
private:

    // Arrays to store player data
    int playerCount;
    int playerArray[100];
    int idArray[100];
    int posArray[100];
    
public:
    // Constructor
    Player(); // Default constructor
    Player(int); // Constructor with player count

    // Getters
    int getPlayerCount(); // Get player count
    int getPlayer(int); // Get player
    int getId(int); // Get player ID
    int getPosition(int); // Get player position

    // Setters
    void setPosition(int, int);
};

#endif