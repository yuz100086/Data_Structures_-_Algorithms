/**
 * File name: BitOutputStream.cpp
 * Name: Yucheng Zhang & Yupei Zhu
 * Account ID: cs100scy & cs100sdb
 * Description: A cpp file implements the methods in BitOutputStream class
 * Date: 04/23/2016
 */
#include "BitOutputStream.hpp"
#define EIGHT 8
#define MASK 0x80

/** flush the buffer */
void BitOutputStream::flush() {
    out.put(buf<<(EIGHT-nbits));
    out.flush();
    buf = nbits = 0;
}

/** put a bit in to the out stream */
void BitOutputStream::putBit(int bit) {
    
    if (nbits == EIGHT)
    {
        flush();
    }
    if (bit == 0)
    {
        buf = buf << 1;
        nbits++;
        return;
    }else {
        buf = (buf << 1) + 1;
        nbits++;
        return;
    }
    
}

/** the number of zeros in the last flush */
void BitOutputStream::tailingZeros(){
    unsigned char zeros = EIGHT-nbits;
    flush();
    putChar(zeros);
    flush();
}

/** put char in to the output file */
void BitOutputStream::putChar(unsigned char ch) {
    for (int i = 0; i < EIGHT; i++)
    {
        putBit((ch<<i)&MASK);
    }
}