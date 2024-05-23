#include "Board.h"
#include <cstdlib>
#include <ctime>

int random(int v1, int v2);
bool srand_called = false;
bool in(int val, int* arr);

Board::Board(){
  int lpos[ladders]; // Ladders positions
  int spos[snakes]; //Snakes positions
  int n_;

  for (int i = 0; i<30; i++){
    Table[i] = 'N'; //Define all tiles to a N
  }

  for (int j = 0; j<ladders; j++){
    n_ = random(7,26); //Makes a random selection of tiles 

      while(in(n_, lpos)){  //Checks if that position is free
        n_ = random(7,26);
      }

    Table[n_] = 'L'; //Change the value of the tile
    lpos[j] = n_; //Storage the new ladder position
  }

  //Repeate for snakes
  for (int j = 0; j<snakes; j++){
    n_ = random(7,26);

    while(in(n_, spos) || in(n_, lpos) ){
      n_ = random(7,26);
    }
    Table[n_] = 'S';
    spos[j] = n_;
  }
}


bool in(int val, int* arr){
  //This function check if a value is inside of an array
  int ans;
  int l = sizeof(arr)/sizeof(int);

  for(int i = 0; i<l; i++){
    if (val == arr[i]){
      return true;
    }
  }
  return false;
}

int random(int v1, int v2) {
    if (!srand_called) {
        srand((unsigned int)time(NULL));
        srand_called = true;
    }

    int n = v2 - v1;
    return (rand() % (n + 1)) + v1;
}
