#include "Board.h"
#include <cstdlib>
#include <ctime>

int random(int v1, int v2);
bool srand_called = false;
bool in(int val, int* arr);

Board::Board(){
  int lpos[ladders];
  int spos[snakes];
  int n_;

  for (int i = 0; i<30; i++){
    Table[i] = 'N';
  }

  for (int j = 0; j<ladders; j++){
    n_ = random(0,29);

    while(in(n_, lpos)){
      n_ = random(0,29);
    }
    Table[n_] = 'L';
    lpos[j] = n_;
  }

  for (int j = 0; j<snakes; j++){
    n_ = random(0,29);

    while(in(n_, spos) || in(n_, lpos)){
      n_ = random(0,29);
    }
    Table[n_] = 'S';
    spos[j] = n_;
  }
}

bool in(int val, int* arr){
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

void Board::getMatrix()
{
    // Prints the type of the element on the table by index
    for(int i = 0; i < 30; i++)
    {
        cout << Table[i] << endl;
    }
}

