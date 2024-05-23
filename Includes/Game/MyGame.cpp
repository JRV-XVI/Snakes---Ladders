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
  board.getMatrix();  //Get the tiles that make up the board

  while (1){
    //To get the record of which turn is
    
    //Player 1 turn
    MyGame::handlopt(); //If the option is not continue it will end the program

    int num=dice.roll(); //Roll the Dice
    
    //Needed info for Player 1
    cout << "Turn: " << turn << endl;
    cout <<"Player ID: "<<P1.getId()<<endl<<"Position: "<<P1.getPosition()<<endl; // player ID and Position
    cout <<"Number Rolled:  "<< num<<endl; // number rolled

    P1.setPosition(P1.getPosition()+num); //set new Player position
    cout <<"New position: "<< P1.getPosition()<<endl;

    //Needed info for Player 2
    MyGame::handlopt(); //If the option is not continue it will end the program

    num=dice.roll(); //Roll the Dice
    
    //Needed info for Player 2
    cout << "Turn: " << turn << endl;
    cout <<"Player ID: "<<P2.getId()<<endl<<"Position: "<<P2.getPosition()<<endl; // player ID and Position
    cout <<"Number Rolled:  "<< num<<endl; // number rolled

    P2.setPosition(P2.getPosition()+num); //set new Player position
    cout <<"New position: "<< P2.getPosition()<<endl;
  }
}
