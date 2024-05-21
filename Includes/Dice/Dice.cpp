#include "Dice.h"

Dice::Dice() {

     result = 0;
     sides = 12;

}

int Dice::roll()
{
    srand((unsigned int) time(NULL));
    return (rand() % sides) + 1;
}
