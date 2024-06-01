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

Square.o: Includes/Square/Square.cpp Includes/Square/Square.h 
	g++ -c -o Square.o Includes/Square/Square.cpp

Ladder.o: Includes/Square/Ladder.cpp Includes/Square/Ladder.h Square.o
	g++ -c -o Ladder.o Square.o Includes/Square/Ladder.cpp

Snake.o: Includes/Square/Snake.cpp Includes/Square/Snake.h Square.o
	g++ -c -o Snake.o Square.o Includes/Square/Snake.cpp
