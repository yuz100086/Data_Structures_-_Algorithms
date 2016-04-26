/**
 * File name: BitInputStream.hpp
 * Name: Yucheng Zhang & Yupei Zhu
 * Account ID: cs100scy & cs100sdb
 * Description: A hpp file definition the methods in BitInputStream class
 * Date: 04/23/2016
 */
#include <iostream>
#define EIGHT 8

class BitInputStream
{
private:
    char buf;
    int nbits;
    std::istream & in;
    bool eof;
    unsigned long long totalBytes, readBytes;
    int tailingZero;
public:
    /** Initialize a BitInputStream that will use
     * the given istream for input
     */
    BitInputStream(std::istream & is) : in(is) {
        
        std::streampos begin,end;
        
        buf = 0;
        readBytes = 0;
        nbits = EIGHT;
        eof = false;
        
        begin = in.tellg();
        in.seekg (0, std::ios::end);
        end = in.tellg();
        totalBytes = end - begin;
        
        in.seekg(-1, std::ios::end);
        tailingZero = in.get();
        in.seekg(0, std::ios::beg);
    }
    
    /** Fill the buffer from the input */
    void fill();
    
    /** get a bit from the input */
    int getBit();
    
    /** get the char */
    unsigned char getChar();
};