/**
 * File name: uncompress.cpp
 * Name: Yucheng Zhang & Yupei Zhu
 * Account ID: cs100scy & cs100sdb
 * Description: This file contains the main method that perform uncompressing a
 * compressed file and output to a out file.
 * Date: 04/13/2016
 */
#include <fstream>
#include <vector>
#include <cstdio>
#include <ctime>
#include "HCTree.hpp"
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

    // check if the file is empty
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

    // reset the stream to beginning of file
    in.seekg(0, ios_base::beg);
    
    // create the bit input stream
    BitInputStream bitIn(in);
    
    // read the whole file and count the frequency
    vector<int> freqs(ASCIINUM,0);
    unsigned int count;
    for (int i = 0; i < ASCIINUM; ++i)
    {
        count = bitIn.getNum();
        freqs[i] = count;
    }
    
    // open the out file
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
    
    // create the tree
    HCTree* tree = new HCTree();
    tree->build(freqs);

    // get the number of characters in the file
    int number = 0;
    for (int i = 0; i < ASCIINUM; ++i)
    {
        number += freqs[i];
    }
    
    // write each char to out
    for (int i = 0; i < number; ++i)
    {
        out << (unsigned char)tree->decode(bitIn);
    }
    
    // delete tree
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