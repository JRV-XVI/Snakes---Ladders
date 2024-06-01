#include "Snake.h"

Snake::Snake(int newEffect){
  effect = newEffect;
}

char Snake::getSymbol (){
  return symbol; 
}

int Snake::getEffect (){
  return effect;
}
