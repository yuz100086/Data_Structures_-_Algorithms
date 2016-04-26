/**
 * File name: BitOutputStream.cpp
 * Name: Yucheng Zhang & Yupei Zhu
 * Account ID: cs100scy & cs100sdb
 * Description: The BitOutputStream class. Contains implementation of methods.
 * Date: 04/13/2016
 */

#include "BitOutputStream.hpp"
#include <bitset>
#define EIGHT 8
#define MASK 0xFF0000
#define SIZE 3

/** Flush the current buffer */
void BitOutputStream::flush() {
    out.put(buf<<(EIGHT-nbits));
    out.flush();
    buf = nbits = 0;
}

/** Put bit into the buffer */
void BitOutputStream::putBit(int bit) {
    // when buffer is full flush
    if (nbits == EIGHT)
    {
        flush();
    }
    
    // when bit is 0
    if (bit == 0)
    {
        buf = buf << 1;
        nbits++;
        return;
    }else { // when bit is 1
        buf = (buf << 1) + 1;
        nbits++;
        return;
    }
    
}

/** Put the ascii symbol's frequency to outfile */
void BitOutputStream::putNum(unsigned int num) {
    unsigned int mask = MASK;
    // put the 24 bits of the number to out
    for (int i = SIZE; i > 0; --i)
    {
        out.put((num&mask)>>((i-1)*EIGHT));
        mask = mask>>EIGHT;
    }
}