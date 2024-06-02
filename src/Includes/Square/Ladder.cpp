#include "Ladder.h"

Ladder::Ladder(int newEffect){
  effect = newEffect;
}

char Ladder::getSymbol (){
  return symbol; 
}

int Ladder::getEffect (){
  return effect;
}
