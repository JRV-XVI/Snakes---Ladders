#include<iostream>
#include "MyGame.h"
#include "Board.h"
#include "Player.h"
#include "Dice.h"

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
  Player P1 (1); //set players and player IDs
  Player P2 (2);

  Board board; //Build board
  Dice dice; // create and roll Dice

  int steps; // position after tile effects
  int num; // Number on wich the dice land on

  board.getMatrix();  //Get the tiles that make up the board

  while (1){
    //To get the record of which turn is
    
    
    //Player 1 turn
    MyGame::handlopt(); //If the option is not continue it will end the program

    num=dice.roll(); //Roll the Dice
    // apply tile effects
    if (P1.getPosition()+num<29)
    {
    if (board.Table[P1.getPosition()+num-1]=='S'){
      steps=P1.getPosition()+num-3;
    }
    else if (board.Table[P1.getPosition()+num-1]=='L')
    {
      steps=P1.getPosition()+num+3;
    }
    else{
      steps=P1.getPosition()+num;
    }
    
    //Needed info for Player 1
    cout << "Turn: " << turn << endl;
    cout <<"Player ID: "<<P1.getId()<<endl<<"Position: "<<P1.getPosition()<<endl; // player ID and Position
    cout <<"Number Rolled:  "<< num<<endl; // number rolled
    cout <<"Tile type: "<< board.Table[P2.getPosition()+num-1]<<endl; // type of tile landed on
    P1.setPosition(steps); //set new Player position
    cout <<"New position: "<< P1.getPosition()<<endl;
    }
    else{
      cout << "Player 1 rolled a "<<num<< "a won" << endl;
      exit(0);
    }
    
    //Needed info for Player 2
    MyGame::handlopt(); //If the option is not continue it will end the program
    if (P2.getPosition()+num<29)
    {
    num=dice.roll(); //Roll the Dice
    // apply tile efects
    if (board.Table[P2.getPosition()+num-1]=='S'){
      steps=P2.getPosition()+num-3;
    }
    else if (board.Table[P2.getPosition()+num-1]=='L')
    {
      steps=P2.getPosition()+num+3;
    }
    else{
      steps=P2.getPosition()+num;
    }

    //Needed info for Player 2
    cout << "Turn: " << turn << endl;
    cout <<"Player ID: "<<P2.getId()<<endl<<"Position: "<<P2.getPosition()<<endl; // player ID and Position
    cout <<"Number Rolled: "<< num<<endl; // number rolled
    cout <<"Tile type: "<< board.Table[P2.getPosition()+num-1]<<endl; // type of tile landed on
    P2.setPosition(steps); //set new Player position
    cout <<"New position: "<< P2.getPosition()<<endl;
    }
    else{
      cout << "Player 2 rolled a "<<num<< "a won" << endl;
      exit(0);
    }
  }
}
