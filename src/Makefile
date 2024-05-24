snake: Board.o Dice.o MyGame.o Player.o 
	g++ -o snake.o snakes.cpp Board.o Dice.o MyGame.o Player.o

Board.o: Includes/Board/Board.cpp Includes/Board/Board.h
	g++ -c -o Board.o Includes/Board/Board.cpp

Dice.o: Includes/Dice/Dice.cpp Includes/Dice/Dice.h
	g++ -c -o Dice.o Includes/Dice/Dice.cpp

MyGame.o: Includes/Game/MyGame.cpp Includes/Game/MyGame.h
	g++ -c -o MyGame.o Includes/Game/MyGame.cpp 

Player.o: Includes/Player/Player.cpp Includes/Player/Player.h
	g++ -c -o Player.o Includes/Player/Player.cpp
