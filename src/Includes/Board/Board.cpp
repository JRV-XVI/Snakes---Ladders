#include "Board.h"
#include <cstdlib>
#include <ctime>
#include <vector>

#include "../Square/Square.h"
#include "../Square/Snake.h"
#include "../Square/Ladder.h"

int random(int v1, int v2);
bool srand_called = false;


Board::Board(){
  setBoard();
}

Board::Board(int newSize, int newSnakes, int newLadders,
        int newLadderEffect, int newSnakeEffect){

  size = newSize;
  snakes = newSnakes;
  ladders = newLadders;
  ladderEffect = newLadderEffect;
  snakeEffect = newSnakeEffect;

  setBoard();
}

void Board::setBoard(){

  int n_;
  int r1, r2; //This will be the ranges of ladders and square appear
  r1 = - snakeEffect; //Snake effect is negative so (-)(-) = +
  r2 = size - ladderEffect;

  Square *iter;

  for (int i = 0; i<size; i++){
    Table.push_back(new Square); //Define all tiles to be the basic square
  }

  for (int j = 0; j<ladders; j++){
    n_ = random(1,r2); //Makes a random selection of tiles 
    iter = Table[n_];

    while(iter->getSymbol() != 'N'){  //Checks if that position is free
      n_ = random(1,r2);
      iter = Table[n_];
    }

    Table[n_] = new Ladder(ladderEffect);
  }

  //Repeate for snakes
  for (int j = 0; j<snakes; j++){
    n_ = random(r1,size-1);
    iter = Table[n_];

    //This will try to find a valid index that is not used
    //and it does not imply a circular path
    while(iter->getSymbol() != 'N' || checkCircularPath(n_)){
      n_ = random(r1, size-1);
      iter = Table[n_];
    }

    Table[n_] = new Snake(snakeEffect); //Change the value of the tile
  }
}

bool Board::checkCircularPath(int index){
  vector <int> indexs; //array of all index passed
  int eff;
  Square *iter_; //sets a iterator

  while(1){
    indexs.push_back(index); //Add the last index we were
    iter_ = Table[index]; //Gets the item
    eff = iter_->getEffect(); //Gets the effect

    index += eff; //Gets the new index

    //If the new index is tha same of previous return false
    //there is no a circular path
    if (index == indexs[indexs.size()-1]) return false;

    //Else check if the new index were before in our path
    for (int i = 0; i < indexs.size() - 1; i++){
      //If yes, return true, there is a circular path
      if (index == indexs[i]) return true;
    }
  }
}

int random(int v1, int v2) {
    if (!srand_called) {
        srand((unsigned int)time(NULL));
        srand_called = true;
    }

    int n = v2 - v1;
    return (rand() % (n + 1)) + v1;
}

