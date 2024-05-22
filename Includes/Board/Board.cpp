#include "Board.h"
#include <cstdlib>
#include <ctime>

int random(int v1, int v2);
int in(int val, int* arr);

Board::Board(){
  int lpos[ladders];
  int spos[snakes];

  for (int i = 0; i<30; i++){
    Table[i] = 'N';
  }

  for (int j = 0; j<ladders; j++){
    int n_ = random(0,29);

    while(in(n_, lpos)){
      n_ = random(0,29);
    }
    Table[j] = 'L';
    lpos[j] = n_;
  }

  for (int j = 0; j<snakes; j++){
    int n_ = random(0,29);

    while(in(n_, spos)){
      n_ = random(0,29);
    }
    Table[j] = 'S';
    spos[j] = n_;
  }
}

int in(int val, int* arr){
  int ans;
  int l = sizeof(arr)/sizeof(int);

  for(int i = 0; i<l; i++){
    if (val == arr[i]){
      return 1;
    }
  }
  return 0;
}

int random(int v1, int v2){
  int n;
  n = v2 - v1;

  srand((unsigned int) time(NULL));
  return (rand() % (n+1) ) + v1;
}

void Board::getMatrix()
{
    // Prints the type of the element on the table by index
    for(int i = 1; i <= 30; i++)
    {
        cout << Table[i] << endl;
    }

}

