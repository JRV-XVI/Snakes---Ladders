#include<iostream>
#include "MyGame.h"
#include "../Board/Board.h"
#include "../Player/Player.h"
#include "../Dice/Dice.h"
#include "../Square/Snake.h"
#include "../Square/Square.h"
#include "../Square/Ladder.h"

using namespace std;
  
void MyGame::start(){
  cout << "Press C to continue next turn, or  E to end the game" << endl;
  cin >> option;
  
  if (option != 'E' && option != 'C'){
    cout << "Invalid option please." << endl;
    MyGame::start();
    exit(0);
  }

  if (option != 'C'){
    cout << "--GAME OVER--" << endl;
    exit(0);
  }

  MyGame::mainloop();
}

void MyGame::handlopt(){
    cout << "Press C to continue next turn" << endl;
    cout << "Press E to end the game" << endl;
    cin >> option;
    
    while( option != 'E' && option != 'C'){
      cout << "Invalid option, please press C to continue next turn or E to end the game"  << endl;
      cin >> option;
    }

    if (option != 'C'){
      cout << "--GAME OVER--" << endl;
      exit(0);
    } 
    turn ++;
    
}

int MyGame::mainloop(){
  char gameConfig;
  cout<<"if you would like to change the game settings enter C, or D if you would like  the default setting: ";
  cin>>gameConfig;
  while (gameConfig !='D' && gameConfig !='C')
  {
    cout<<"it seems like you entered a non-valid option, try again: ";
    cin>>gameConfig;
  }
  
  if (gameConfig == 'D'){
    Player playerList;
    Board board;
  }
  else{
    int numPlayers;
    int size;
    int numSnakes;
    int numLadders;
    int snakeEffect;
    int ladderEffect;

    cout<<"Please enter the amaount of players: ";
    cin>>numPlayers;
    Player playerList(numPlayers);

    cout<<"Now enter the amoun of tiles you want in de game board";
    cin>>size;
    cout<<"Enter the amount on snakes: ";
    cin>>numSnakes;
    cout<<"Enter the amount of laddes: ";
    cin>>numLadders;
    cout<<"Enter the tile efect for ladder tiles: ";
    cin>>ladderEffect;
    cout<<"And finally enter the effect for snake tiles: ";
    cin>>snakeEffect;
    Board board(size,numSnakes,numLadders,ladderEffect,snakeEffect);

  }
  
  Square *iter; //This will be iterating on the board
  
  Dice dice; // create and roll Dice

  int steps; // position after tile effects
  int num; // Number on wich the dice land on

  cout << board << endl;  //Get the tiles that make up the board

  while (1){
    //To get the record of which turn is
    
    //Player 1 turn
    MyGame::handlopt(); //If the option is not continue it will end the program

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

    
    //Needed info for Player 2
    MyGame::handlopt(); //If the option is not continue it will end the program 
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
    }
}
