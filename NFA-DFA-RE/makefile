CC = g++
DELETE = del
.PHONY: clean

default: main

main: main.cpp NFA.cpp DFA.cpp RE.cpp
	$(CC) -o main main.cpp NFA.cpp DFA.cpp RE.cpp -O3

