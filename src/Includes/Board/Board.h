#ifndef BOARD
#define BOARD
#include<iostream>
#include<vector>
#include "../Square/Square.h"


using namespace std;

class Board
{
private:
    /* data */
    int snakes = 3; // Limits of snake tiles
    int ladders = 3; // Limits of ladder tiles
    int size = 30;
    int ladderEffect = 3;
    int snakeEffect = -3;
    vector <Square*> Table; //Table for the ladders and snakes


public:
    Board(); // Constructor
    Board(int newSize, int newSnakes, int newLadders,
        int newLadderEffect, int newSnakeEffect); // Constructor of different size

    void setBoard();
    void getMatrix(); // Method to check the setting of table (snake, ladder, empty)
    bool checkCircularPath(int index); // Will avoid un finish excecutions 

    friend ostream& operator<<(ostream& os, Board b){
      for(int i = 0; i < 30; i++){
        os << b.Table[i] << " ";
      }
      return os;
    }
};

#endif
