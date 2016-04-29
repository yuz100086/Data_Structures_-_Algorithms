#this is a Makefile for double link list

CC=g++
CXXFLAGS=-std=c++11 -g
LDFLAGS=-g

Main: DLTree.o DLNode.o

DLTree.o: DLTree.hpp DLNode.hpp

DLNode.o: DLNode.hpp

clean:
    -f rm Main *.o core*