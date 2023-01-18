Algorithm := $(wildcard Algorithm/*.cpp)
Commands := $(wildcard Commands/*.cpp)
Data := $(wildcard Data/*.cpp)
Distances := $(wildcard Distances/*.cpp)
Main := $(wildcard *.cpp)

AlgorithmObj := $(patsubst %.cpp,%.o,$(Algorithm))
CommandsObj := $(patsubst %.cpp,%.o,$(Commands))
DataObj := $(patsubst %.cpp,%.o,$(Data))
DistancesObj := $(patsubst %.cpp,%.o,$(Distances))
MainObj := $(patsubst %.cpp,%.o,$(Main))

run: $(AlgorithmObj) $(CommandsObj) $(DataObj) $(DistancesObj) $(MainObj)
	g++ -std=c++11 -pthread Distances/*.o Commands/*.o Data/*.o Algorithm/*.o SocketIO.o CLI.o server.o -o server.out
	g++ -std=c++11 -pthread Distances/*.o Data/*.o Algorithm/*.o SocketIO.o client.o -o client.out

clean:
	rm Algorithm/*.o
	rm Commands/*.o
	rm Data/*.o
	rm Distances/*.o
	rm *.o
	rm *.out