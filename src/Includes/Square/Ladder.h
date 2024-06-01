#ifndef LADDER 
#define LADDER
#include "Square.h"

class Ladder: public Square {
  private:
    char symbol = 'L';
    int effect = 3;
  
  public:
    char getSymbol() override;
    int getEffect() override;
};

#endif // !LADDER
