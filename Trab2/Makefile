all: main

main: graph.o main.o gmlparser.o
	g++ -std=c++11 -g -o main main.o graph.o parser.o

parser.o: parser.cpp
	g++ -std=c++11 -c parser.cpp

graph.o: graph.cpp
	g++ -std=c++11 -c graph.cpp

main.o: main.cpp
	g++ -std=c++11 -c main.cpp