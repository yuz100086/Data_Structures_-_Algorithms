#A Makefile

cc=g++
CXXFLAGS=-std=c++11 -g
LDFLAGS=-g

all: TSTMain

TSTMain: TSTTree.o TSTNode.o

TSTTree.o: TSTTree.hpp

TSTNode.o: TSTNode.hpp

clean: 
	rm -f TSTMain *.o core.*