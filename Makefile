
all: main

main: main.cpp
	g++ main.cpp -o a.out -O2 -Wall -lSDL2 -g -Wfatal-errors

