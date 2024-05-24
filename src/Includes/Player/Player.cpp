#include "Player.h"

Player::Player(int playerId) {
    id = playerId;
}


int Player::getId() {
    return id;
}

int Player::getPosition()  {
    return position;
}


void Player::setPosition(int newPosition) {
    position = newPosition;
}
