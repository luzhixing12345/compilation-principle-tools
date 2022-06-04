CC = g++
DELETE = del
.PHONY: clean

default: main


main : main.cpp FFS_set.cpp
	$(CC) -o main main.cpp FFS_set.cpp -O3

clean:
	-$(DELETE) main.exe