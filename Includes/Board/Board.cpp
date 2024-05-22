#include "Board.h"

Board::Board()
{
    int stateTile = 0; // Switch to change a snake/ladder tile
    for(int index = 1; index <= 30; index++) {
        // Snake tile
        if(index % 7 == 0 && stateTile != 0 && snakes > 0) {
            Table[index] = 'S';
            stateTile = 0;
            snakes -= 1;
        }
        // Ladder tile
        else if(index % 8 == 0 && stateTile == 0 && ladders > 0)
        {
            Table[index] = 'L';
            stateTile = 1;
            ladders -= 1;
        }
        // Empty tile
        else {
            Table[index] = 'N';
        }
    }
}

void Board::getMatrix()
{
    // Prints the type of the element on the table by index
    for(int i = 1; i <= 30; i++)
    {
        cout << Table[i] << endl;
    }

}