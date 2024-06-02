#include "Player.h"
#include <iostream>

// Constructor
Player::Player() {
    playerCount = 2;
    for(int i = 0; i < playerCount; i++) {
        playerArray[i] = i + 1;
        idArray[i] = i + 1;
        posArray[i] = 1;
    }
}

Player::Player(int players) {
    playerCount = players;
    for(int i = 0; i < playerCount; i++) {
        playerArray[i] = i + 1;
        idArray[i] = i + 1;
        posArray[i] = 1;
    }
}

// Getters
int Player::getPlayerCount() {
    return playerCount;
}

int Player::getPlayer(int index) {
    return playerArray[index];
}

int Player::getId(int index) {
    return idArray[index];
}

int Player::getPosition(int index) {
    return posArray[index];
}

void Player::setPosition(int index, int position) {
    posArray[index] = position;
}