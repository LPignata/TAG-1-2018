all: main

main: graph.o main.o gmlparser.o
	g++ -std=c++11 -g -o main.exe main.o graph.o gmlparser.o

gmlparser.o: gmlparser.cpp
	g++ -std=c++11 -c gmlparser.cpp

graph.o: graph.cpp
	g++ -std=c++11 -c graph.cpp

main.o: main.cpp
	g++ -std=c++11 -c main.cpp