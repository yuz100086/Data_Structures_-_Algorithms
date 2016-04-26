/**
 * File name: BitInputStream.cpp
 * Name: Yucheng Zhang & Yupei Zhu
 * Account ID: cs100scy & cs100sdb
 * Description: The BitInputStream class. Contains implementation of methods.
 * Date: 04/13/2016
 */
#include "BitInputStream.hpp"
#define BITMASK 0x80
#define SIZE 3
#define EIGHT 8

/** Fill the buffer from the input */
void BitInputStream::fill() {
    buf = in.get();
    nbits = 0;
}

/** Get bit from the input buffer */
int BitInputStream::getBit() {
    // need to renew buf
    if (nbits == EIGHT)
    {
        fill();
    }
    
    // get the bit and it is 0
    if ((buf & BITMASK) == 0) {
        buf = buf << 1;
        nbits++;
        return '0';
    }else{ // the bit is 1
        buf = buf << 1;
        nbits++;
        return '1';
    }
}

/** Get the number of ascii symbol from input */
unsigned int BitInputStream::getNum() {
    unsigned int temp = 0;
    // get three bytes
    for (int i = 0; i < SIZE; ++i)
    {
        temp = (temp << EIGHT) + in.get();
    }

    return temp;
}