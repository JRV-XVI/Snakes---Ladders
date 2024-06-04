#ifndef GAMETYPE
#define GAMETYPE

#include "../Player/Player.h"
#include "../Board/Board.h"
#include "../Square/Square.h"
#include "../Square/Ladder.h"
#include "../Square/Snake.h"
#include "../Dice/Dice.h"

class GameType {
  private:
    int turn = 0;
    int maxTurn;
    int winnerByDefault=0;
    Player playerList;
    Board board;

  public:
    GameType(); // Manual for 2 players
    GameType(char option); // Automatic for 2 players
    GameType(char option, int newSize, int newSnakes, int newLadders,
        int newLadderEffect, int newSnakeEffect, int players,int turnLimit); // Costum game configuration

    void handlopt();
    void checkTurn();
};

#endif