# A simple makefile for CSE 100 PA2

CC=g++
CXXFLAGS=-std=c++11 -g
LDFLAGS=-g

all: compress uncompress

testIn: test

test: BitInputStream.o BitOutputStream.o

compress: HCNode.o HCTree.o BitOutputStream.o BitInputStream.o

uncompress: HCNode.o HCTree.o BitOutputStream.o BitInputStream.o

HCTree.o: HCNode.hpp HCTree.hpp BitOutputStream.hpp BitInputStream.hpp

HCNode.o: HCNode.hpp

BitOutputStream.o: BitOutputStream.hpp

BitInputStream.o: BitInputStream.hpp

clean:
	rm -f compress uncompress *.o core*

