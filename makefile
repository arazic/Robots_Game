Prog: Game.o Robot.o Map.o main.o 
	g++  Game.o Robot.o Map.o main.o -o Prog

Map.o: Map.h Map.cpp
	g++  -c  Map.cpp

Robot.o: Robot.cpp Robot.h  
	g++  -c  Robot.cpp

Game.o: Game.cpp Game.h Map.h Robot.h 
	g++  -c  Game.cpp

main.o: main.cpp
	g++  -c  main.cpp
clean: 
	rm -f *.o


