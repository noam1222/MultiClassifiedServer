run:
	g++ -std=c++11 Distances/*.cpp Commands/*.cpp Data/*.cpp Algorithm/*.cpp SocketIO.cpp CLI.cpp server.cpp -o server.out
	g++ -std=c++11 Distances/*.cpp Data/*.cpp Algorithm/*.cpp SocketIO.cpp client.cpp -o client.out

clean:
	rm *.out