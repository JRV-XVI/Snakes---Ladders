#include "Dice.h"

Dice::Dice() {

     result = 0;
     sides = 12;

    srand((unsigned int) time(NULL)); //Extra line of code to seed the random number generator
}

int Dice::roll()
{
    //srand((unsigned int) time(NULL));
    return (rand() % sides) + 1;
}

