/**
 *  Filename: TSTNode.hpp
 *  Name: Yucheng Zhang
 *  Github: yuz100086
 *  Description: This is the TSTNode.hpp file, it contains the definition of the
 *               ternary search tree's node's definition.
 *  Date: 04/25/16
 */
#ifndef TSTNODE_HPP
#define TSTNODE_HPP

#include <string>

typedef unsigned char letter;
using namespace std;

class TSTNode
{
public:
    letter symbol;
    int count;
    TSTNode* down;
    TSTNode* right;
    TSTNode* left;

	TSTNode(letter symbol,
            int count, 
            TSTNode* down = 0, 
            TSTNode* right = 0, 
            TSTNode* left = 0): 
            symbol(symbol), count(count), down(down), right(right), left(left){}
	
	
};
#endif