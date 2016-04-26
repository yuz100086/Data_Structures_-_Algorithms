/**
 * File name: compress.cpp
 * Name: Yucheng Zhang & Yupei Zhu
 * Account ID: cs100scy & cs100sdb
 * Description: This file contains the main method that performs compressing a
 * input file and output to a out file.
 * Date: 04/13/2016
 */
#include <fstream>
#include <vector>
#include "AHCTree.hpp"
#define ASCIINUM 256

int main(int argc, char const *argv[])
{
    /* check number of arguments */
    if (argc != 3)
    {
        return -1;
    }

    // open file
    ifstream in;
    in.open(argv[1], ios::binary);
    
    // check if input file is open
    if (!in.is_open())
    {
        cout<< "Invalid input file. No file was opened. Please try again.\n";
        return -1;
    }
    
    in.seekg(0, ios_base::end);
    unsigned int len = in.tellg();
    if (len == 0)
    {
        // open the output file
        ofstream out;
        out.open(argv[2], ios::binary);
        
        // close streams
        if (in.is_open())
        {
            in.close();
        }
        
        if (out.is_open())
        {
            out.close();
        }
        
        return 0;
    }
    
    in.seekg(0, ios_base::beg);
    
    
    // open the output file
    ofstream out;
    out.open(argv[2], ios::binary);
    
    // check whether out file is open
    if (!out.is_open())
    {
        cout<< "Invalid output file. No file was opened. Please try again.\n";
        
        // close streams
        if (in.is_open())
        {
            in.close();
        }
        return -1;
    }
    
    BitOutputStream bitOut(out);
    
    // creat the tree
    AHCTree* tree = new AHCTree();
    // encode each char in the in file
    int ch;

    
    while((ch = in.get()) != EOF) {
        tree->encode((unsigned char)ch, bitOut);
    }
    bitOut.tailingZeros();
    
    // delete the tree
    delete tree;
    
    // close streams
    if (in.is_open())
    {
        in.close();
    }
    
    if (out.is_open())
    {
        out.close();
    }

    return 0;
}