#ifndef DICE
#define DICE

#include <cstdlib>
#include <ctime>
#include <iostream>

//using namespace std;

class Dice
{

private:
   int sides;

public:
   int result;

   Dice();  
   int roll();

};

#endif
