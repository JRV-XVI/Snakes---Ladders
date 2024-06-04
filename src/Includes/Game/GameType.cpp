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
    maxTurn = 4;
    int steps; // position after tile effects
    int num; // Number on wich the dice land on

    cout << board << endl;  //Get the tiles that make up the board

    while (true) {
        for (int index = 0; index < 2; index++) {
            turn++;
            GameType::handlopt(); //If the option is not continue it will end the program
            cout << endl;
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
            GameType::checkTurn();//Checking for max turn
        }
    }
}

GameType::GameType(char option) {
    playerList = Player(); //set playerList
    board = Board(); //Build board
    Dice dice;
    Square *iter;
  
    int num = 0; // Number on wich the dice land on
    int steps = 0; // position after tile effects
    maxTurn = 4;

    cout << board << endl;  //Get the tiles that make up the board

    while (true) {
        for (int index = 0; index < 2; index++) {
            turn++;
            cout << endl;
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
            GameType::checkTurn();//Checking for max turn
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
                GameType::checkTurn();//Checking for max turn
            }

        }
    }

    else {
    
        while (true) {
            
            for (int index = 0; index < playerList.getPlayerCount(); index++) {
                turn++;
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
                GameType::checkTurn();//Checking for max turn
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
    if (turn>=maxTurn){
        for (int i=1;i<playerList.getPlayerCount();i++){
            if (playerList.getPosition(winnerByDefault)<playerList.getPosition(i)){
                winnerByDefault=i;
            }
        cout<<"The max turn limit has been reached, Player "<<winnerByDefault+1<<" has won by default with a total of "<<playerList.getPosition(winnerByDefault)<<" tiles, got the max distance first"<<endl;
        exit(0);
        }
        
}

}
