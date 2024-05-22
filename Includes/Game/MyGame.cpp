#include<iostream>
#include "MyGame.h"

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
    
}

int MyGame::mainloop(){
  while (1){
    //To get the record of which turn is
    turn ++;
    MyGame::handlopt(); //If the option is not continue it will end the program

    //Needed info
    cout << "Turn: " << turn << endl;

  }
}
