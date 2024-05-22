#ifndef BOARD
#define BOARD

#include "iostream"
using namespace std;

class Board
{
private:
    /* data */
    int snakes = 3; // Limits of snake tiles
    int ladders = 3; // Limits of ladder tiles
public:
    char Table[30]; // Table of 30 tiles
    Board(); // Constructor
    void getMatrix(); // Method to check the setting of table (snake, ladder, empty)
};

#endif
