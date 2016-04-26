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

    // read the whole file and count the frequency
    vector<int> freqs(ASCIINUM,0);
    int ch;


    while((ch = in.get()) != EOF) {
        freqs[(unsigned char)ch]++;
    }

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
    
    // create the bit output stream
    BitOutputStream bitOut(out);
    // write all ascii symbol's count to out
    for (int i = 0; i < freqs.size(); ++i)
        bitOut.putNum(freqs[i]);
    
    // creat the tree
    HCTree* tree = new HCTree();
    tree->build(freqs);

    // encode each char in the in file
    in.clear();
    in.seekg(0, ios_base::beg);
    while((ch = in.get()) != EOF) {
        tree->encode((unsigned char)ch, bitOut);
    }
    bitOut.flush();
    
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