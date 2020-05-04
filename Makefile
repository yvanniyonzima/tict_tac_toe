
C++11 = -std=c++11

tictactoe: main.o Player.o Game.o
	g++ $(C++11) -o tictactoe main.o Player.o Game.o

main.o: main.cc Player.hh Game.hh 
	g++ $(C++11) -c main.cc Player.cc Game.cc

Player.o: Player.cc Player.hh
	g++ $(C++11) -c Player.cc

Game.o: Game.cc Game.hh
	g++ $(C++11) -c Game.cc

clean:
	rm -f *.o tictactoe