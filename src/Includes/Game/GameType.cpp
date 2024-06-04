#include "GameType.h"
#include "../Player/Player.h"
#include "../Player/Player.h"
#include <iostream>
using namespace std;

GameType::GameType() {
    playerList = Player(); //set playerList
    board = Board(); //Build board
    Dice dice;
    Square *iter;
  int maxTurn = 10;
  int steps; // position after tile effects
  int num; // Number on wich the dice land on

  cout << board << endl;  //Get the tiles that make up the board

  while (true){
    //To get the record of which turn is
    turn++;
    checkTurn();//Checking for max turn
    //Player 1 turn
    GameType::handlopt(); //If the option is not continue it will end the program

    num = dice.roll(); //Roll the Dice
    // apply tile effects
    if (playerList.getPosition(0) + num >= 30){
      cout << "Player 1 rolled "<< num << " and won" << endl;
      exit(0);
    }

    iter = board.Table[playerList.getPosition(0) + num - 1];

    //This line makes the update of the position
    steps = playerList.getPosition(0) + num + iter->getEffect();

    //Needed info for Player 1
    cout << "Turn: " << turn << endl;
    cout << "Player ID: "<< playerList.getId(0) << endl;
    cout << "Position: " << playerList.getPosition(0) << endl; // player ID and Position
    cout << "Number Rolled: " << num << endl; // number rolled
    cout << "Tile type: " << iter -> getSymbol() << endl; // type of tile landed on
    playerList.setPosition(0, steps); //set new Player position
    cout << "New position: "<< playerList.getPosition(0) << endl;

    cout << endl;
    turn++;
    checkTurn();//Checking for max turn
    //Needed info for Player 2
    GameType::handlopt(); //If the option is not continue it will end the program 
    num = dice.roll(); //Roll the Dice

    if (playerList.getPosition(1) + num >= 30){
      cout << "Player 2 rolled "<< num << " and won" << endl;
      exit(0);
    }

    // apply tile efects
    iter = board.Table[playerList.getPosition(1) + num - 1];

    //Update the steps of the player
    steps = playerList.getPosition(1) + num + iter->getEffect();

    //Needed info for Player 2
    cout << "Turn: " << turn << endl;
    cout << "Player ID: "<< playerList.getId(1) << endl;
    cout << "Position: "<< playerList.getPosition(1) << endl; // player ID and Position
    cout << "Number Rolled: "<< num <<endl; // number rolled
    cout << "Tile type: "<< iter ->getSymbol() << endl; // type of tile landed on
    playerList.setPosition(1, steps); //set new Player position
    cout << "New position: " << playerList.getPosition(1) << endl;
    cout << endl;
    }
}

GameType::GameType(char option) {
    playerList = Player(); //set playerList
    board = Board(); //Build board
    Dice dice;
    Square *iter;
  
    int num = 0; // Number on wich the dice land on
    int steps = 0; // position after tile effects

    cout << board << endl;  //Get the tiles that make up the board

    while (true) {
        for (int index = 0; index < 2; index++) {
            turn++;
            checkTurn();//Checking for max turn
            cout << endl;
            turn++;
            num = dice.roll(); //Roll the Dice
            // apply tile effects
            if (playerList.getPosition(index) + num >= 30){
            cout << "Player " << playerList.getId(index) << " rolled "<< num << " and won" << endl;
            exit(0);
            }

            iter = board.Table[playerList.getPosition(index) + num - 1];

            //This line makes the update of the position
            steps = playerList.getPosition(index) + num + iter->getEffect();

            //Needed info for Player 1
            cout << "Turn: " << turn << endl;
            cout << "Player ID: "<< playerList.getId(index) << endl;
            cout << "Position: " << playerList.getPosition(index) << endl; // player ID and Position
            cout << "Number Rolled: " << num << endl; // number rolled
            cout << "Tile type: " << iter -> getSymbol() << endl; // type of tile landed on
            playerList.setPosition(index, steps); //set new Player position
            cout << "New position: "<< playerList.getPosition(index) << endl;

        }

    }
}

GameType::GameType(char option, int newSize, int newSnakes, int newLadders, int newLadderEffect, int newSnakeEffect, int players, int turnLimit) {
    playerList = Player(players); //set playerList
    board = Board(newSize, newSnakes, newLadders, newLadderEffect, newSnakeEffect); //Build board
    Dice dice;
    Square *iter;
    maxTurn = turnLimit;

    int num = 0; // Number on wich the dice land on
    int steps = 0; // position after tile effects
    
    cout << board << endl;  //Get the tiles that make up the board

    if (option != 'M') {

        while (true) {
            for (int index = 0; index < playerList.getPlayerCount(); index++) {
                turn++;
                checkTurn();//Checking for max turn
                cout << endl;
                turn++;
                num = dice.roll(); //Roll the Dice
                // apply tile effects
                if (playerList.getPosition(index) + num >= newSize){
                cout << "Player " << playerList.getId(index) << " rolled "<< num << " and won" << endl;
                exit(0);
                }

                iter = board.Table[playerList.getPosition(index) + num - 1];

                //This line makes the update of the position
                steps = playerList.getPosition(index) + num + iter->getEffect();

                //Needed info for Player 1
                cout << "Turn: " << turn << endl;
                cout << "Player ID: "<< playerList.getId(index) << endl;
                cout << "Position: " << playerList.getPosition(index) << endl; // player ID and Position
                cout << "Number Rolled: " << num << endl; // number rolled
                cout << "Tile type: " << iter -> getSymbol() << endl; // type of tile landed on
                playerList.setPosition(index, steps); //set new Player position
                cout << "New position: "<< playerList.getPosition(index) << endl;

            }

        }
    }

    else {
    
        while (true) {
            
            for (int index = 0; index < playerList.getPlayerCount(); index++) {
                turn++;
                checkTurn();//Checking for max turn
                GameType::handlopt(); //If the option is not continue it will end the program
                num = dice.roll(); //Roll the Dice

                if (playerList.getPosition(index) + num >= newSize) {
                    cout << "Player " << playerList.getId(index) << " rolled "<< num << " and won" << endl;
                    exit(0);
                }
                iter = board.Table[playerList.getPosition(index) + num - 1];

                //This line makes the update of the position
                steps = playerList.getPosition(index) + num + iter->getEffect();

                //Needed info for Player 1
                cout << endl;
                cout << "Turn: " << turn << endl;
                cout << "Player ID: "<< playerList.getId(index) << endl;
                cout << "Position: " << playerList.getPosition(index) << endl; // player ID and Position
                cout << "Number Rolled: " << num << endl; // number rolled
                cout << "Tile type: " << iter -> getSymbol() << endl; // type of tile landed on
                playerList.setPosition(index, steps); //set new Player position
                cout << "New position: "<< playerList.getPosition(index) << endl;

            }

        }
    }
}

void GameType::handlopt() {
    char option;
    cout << "Press C to continue next turn" << endl;
    cout << "Press E to end the game" << endl;
    cin >> option;
    
    while( option != 'E' && option != 'C') {
      cout << "Invalid option, please press C to continue next turn or E to end the game"  << endl;
      cin >> option;
    }

    if (option != 'C'){
      cout << "--GAME OVER--" << endl;
      exit(0);
    }
    
}

void GameType::checkTurn(){
    if (turn>maxTurn){
        for (int i=1;i<playerList.getPlayerCount();i++){
            if (playerList.getPosition(winnerByDefault)<playerList.getPosition(i)){
                winnerByDefault=i;

            cout<<"The max turn limit has been reached, Player "<<winnerByDefault+1<<" has won by default with a total of "<<playerList.getPosition(winnerByDefault)<<" tiles"<<endl;
            exit(0);
            }
        }

}

}
