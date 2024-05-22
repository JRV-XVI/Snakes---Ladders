#ifndef PLAYER_H
#define PLAYER_H


class Player {
private:

    int id;
    int position = 1;

public:
    Player(int playerId);


    int getId() ;
    int getPosition() ;


    void setPosition(int newPosition);
};

#endif