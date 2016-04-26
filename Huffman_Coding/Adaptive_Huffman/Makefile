# A simple makefile for CSE 100 PA2

CC=g++
CXXFLAGS=-std=c++11 -g
LDFLAGS=-g

all: compress uncompress

testIn: test

test: BitInputStream.o BitOutputStream.o

compress: AHCTree.o BitOutputStream.o BitInputStream.o

uncompress: AHCTree.o BitOutputStream.o BitInputStream.o

AHCTree.o: AHCNode.hpp AHCTree.hpp BitOutputStream.hpp BitInputStream.hpp

BitOutputStream.o: BitOutputStream.hpp

BitInputStream.o: BitInputStream.hpp

clean:
	rm -f compress uncompress *.o core*

