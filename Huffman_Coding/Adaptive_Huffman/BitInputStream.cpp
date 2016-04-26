/**
 * File name: BitInputStream.cpp
 * Name: Yucheng Zhang & Yupei Zhu
 * Account ID: cs100scy & cs100sdb
 * Description: A cpp file implements the methods in BitInputStream class
 * Date: 04/23/2016
 */
#include "BitInputStream.hpp"
#define EIGHT 8
#define BITMASK 0x80

/** Fill the buffer from the input */
void BitInputStream::fill() {
    buf = in.get();
    readBytes++;
    if(readBytes == totalBytes - 1)
        eof = true;
    nbits = 0;
}

/** get a bit from the input */
int BitInputStream::getBit() {
    // if eof
    if(eof && nbits == EIGHT - tailingZero){
        return EOF;
    }
    
    // renew buffer
    if (nbits == EIGHT)
    {
        fill();
    }
    
    // get the bit and it is 0
    if ((buf & BITMASK) == 0) {
        buf = buf << 1;
        nbits++;
        return 0;
    }else{ // the bit is 1
        buf = buf << 1;
        nbits++;
        return 1;
    }
}

/** get the char */
unsigned char BitInputStream::getChar() {
    unsigned char temp = 0;
    for (int i = 0; i < EIGHT; ++i)
    {
        temp = (temp << 1) + getBit();
    }
    
    return temp;
}