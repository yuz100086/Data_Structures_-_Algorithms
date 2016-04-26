/**
 * File name: BitOutputStream.hpp
 * Name: Yucheng Zhang & Yupei Zhu
 * Account ID: cs100scy & cs100sdb
 * Description: A hpp file definition the methods in BitOutputStream class
 * Date: 04/23/2016
 */
#include <iostream>
class BitOutputStream
{
private:
    unsigned char buf;
    int nbits;
    std::ostream & out;
public:
    /** Initialize a BitOutputStream that will use
     * the given ostream for output
     */
    BitOutputStream(std::ostream & os) : out(os), buf(0), nbits(0) {
        // clear buffer and bit counter
    }
    
    /** flush the buffer */
    void flush();
    
    /** put a bit in to the out stream */
    void putBit(int bit);
    
    /** the number of zeros in the last flush */
    void tailingZeros();
    
    /** put char in to the output file */
    void putChar(unsigned char ch);
    
};