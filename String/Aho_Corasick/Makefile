# A simple makefile for CSE 100 P3

CC=g++
CXXFLAGS=-std=c++11 -g -Wall
LDFLAGS=-g

all: FindAllQueries

FindAllQueries: ACTree.o

ACTree.o: ACTree.hpp ACNode.hpp

clean:
	rm -f FindAllQueries *.o core* *~

