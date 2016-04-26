/**
 * File name: BitOutputStream.hpp
 * Name: Yucheng Zhang & Yupei Zhu
 * Account ID: cs100scy & cs100sdb
 * Description: The BitOutputStream class. Contains definition of methods.
 * Date: 04/13/2016
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

    /** Flush the current buffer */
    void flush();

    /** Put bit into the buffer */
    void putBit(int bit);

    /** Put the ascii symbol's frequency to outfile */
    void putNum(unsigned int num);

};