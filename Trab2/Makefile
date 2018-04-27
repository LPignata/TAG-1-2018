all: main

main: graph.o main.o parser.o
	g++ -std=c++11 -g -o main.exe main.o miniwin.o graph.o parser.o

parser.o: parser.cpp
	g++ -std=c++11 -c parser.cpp

graph.o: graph.cpp
	g++ -std=c++11 -c graph.cpp

miniwin.o: miniwin.cpp
	g++ -std=c++11 -c miniwin.cpp

main.o: main.cpp
	g++ -std=c++11 -c main.cpp