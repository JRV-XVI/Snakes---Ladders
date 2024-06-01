#include "Snake.h"

char Snake::getSymbol override(){
  return symbol; 
}

int Snake::getEffect override(){
  return effect;
}
