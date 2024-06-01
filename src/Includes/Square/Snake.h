#ifndef SNAKE
#define SNAKE
#include "Square.h"

class Snake: public Square {
  private:
    char symbol = 'S';
    int effect = -3;

  public:
    char getSymbol() override;
    int getEffect() override;
};

#endif // !SNAKE
