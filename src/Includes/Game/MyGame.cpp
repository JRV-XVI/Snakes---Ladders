#include <iostream>
#include "MyGame.h"
#include "GameType.h"

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

int MyGame::mainloop(){
  char gameMode; // Manual or Automatic

  cout << "____Menu____" << endl; 
  cout << "M) Manual" << endl; // Manual game configuration
  cout << "A) Automatic" << endl; // Automatic game configuration
  cin >> option;
  
  if (option != 'M' && option != 'A'){
    cout << "Invalid option please." << endl;
    MyGame::mainloop();
    exit(0);
  }

  gameMode = option;

  cout << "D) Default" << endl; // Default game configuration
  cout << "C) Custom" << endl; // Custom game configuration
  cin >> option;
  
  while (option != 'D' && option != 'C'){
    cout << "Invalid option please." << endl;
    cout << "D) Default" << endl;
    cout << "C) Custom" << endl;
    cin >> option;
  }
  
  if (gameMode == 'M' && option == 'D'){
      GameType game;
  }
  else if (gameMode == 'A' && option == 'D') {
    GameType game(gameMode);
  }
  else {
    int newSize, newSnakes, newLadders, newLadderEffect, newSnakeEffect, players, turnLimit;
    cout << "Enter the size of the board" << endl;
    cin >> newSize;
    cout << "Enter the number of snakes" << endl;
    cin >> newSnakes;
    cout << "Enter the number of ladders" << endl;
    cin >> newLadders;
    cout << "Enter the effect of the ladders" << endl;
    cin >> newLadderEffect;
    cout << "Enter the effect of the snakes" << endl;
    cin >> newSnakeEffect;
    cout << "Enter the number of players" << endl;
    cin >> players;
    cout<< "Enter the max number of turns"<<endl;
    cin>> turnLimit;
    
    GameType game(gameMode, newSize, newSnakes, newLadders, newLadderEffect, newSnakeEffect, players, turnLimit);
  }

  return 0;
}
