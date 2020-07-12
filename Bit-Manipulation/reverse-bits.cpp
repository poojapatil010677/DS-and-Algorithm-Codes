/*

Reverse Bits

Reverse bits of a given 32 bits unsigned integer.

*/

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t rev = 0;
        for(int i=0;i<32;i++)
        {
            int temp = (n&1);
            n = n>>1;
            rev = rev | (temp<<(31-i));
        }
        return rev;
    }
};
