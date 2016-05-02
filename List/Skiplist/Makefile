# A simple makefile for CSE 100 P1

#use g++ for everything
CC= g++  	

# include debugging symbols in object files,
# and enable all warnings
CXXFLAGS= -g -Wall -std=c++11

#include debugging symbols in executable
LDFLAGS= -g	
all: benchmark_skiplist

benchmark_skiplist: skiplist.o 
	g++ -o benchmark_skiplist skiplist.o

skiplist.o: skiplist.hpp 

clean:
	$(RM) main bst *.o
