# Snake & ladders

The fundamental OOP concepts implemented in the project were the use of abstraction and encapsulation. The architecture used within the code was with the use of classes, this with the objective of being able to make the implementations that form the simplest form of the snakes and ladders game such as the players, the board, dice and the logic of the game. When implemented in this way, it gives us the flexibility to make use of the attributes of the object to manipulate it in a more efficient way.

UML diagram
![alt text](https://drive.google.com/file/d/1OnOmt6iNDDEMgFiERX7tGPI2ITTVTl1A/view?usp=drive_link)

## Run Locally

Clone the project

```bash
git clone https://github.com/JRV-XVI/snakes-and-ladders.git
```

Go to the project directory

```bash
cd snakes-and-ladders
```

Compile the app

```bash
make snake
```

Or manually
```bash
g++ -c -o Board.o Includes/Board/Board.cpp
g++ -c -o Dice.o Includes/Dice/Dice.cpp
g++ -c -o MyGame.o Includes/Game/MyGame.cpp 
g++ -c -o Player.o Includes/Player/Player.cpp
g++ -o snake.o snakes.cpp Board.o Dice.o MyGame.o Player.o
```

Run the code

```bash
./snake.o
```
