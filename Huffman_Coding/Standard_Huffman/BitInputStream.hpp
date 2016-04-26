/**
 * File name: BitInputStream.hpp
 * Name: Yucheng Zhang & Yupei Zhu
 * Account ID: cs100scy & cs100sdb
 * Description: The BitInputStream class. Contains definition of methods.
 * Date: 04/13/2016
 */

#include <iostream>
#define EIGHT 8

class BitInputStream
{
private:
    char buf;
    int nbits;
    std::istream & in;
public:
    /** Initialize a BitInputStream that will use
      * the given istream for input
      */
    BitInputStream(std::istream & is) : in(is) {
        buf = 0;
        nbits = EIGHT;
    }

    /** Fill the buffer from the input */
    void fill();

    /** Get bit from the input buffer */
    int getBit();
    
    /** Get the number of ascii symbol from input */
    unsigned int getNum();
};