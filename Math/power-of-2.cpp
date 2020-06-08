/*
 Power of 2

Given an integer, write a function to determine if it is a power of two.

Input: 1
Output: true 
Explanation: 20 = 1

*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        long i = 1;
        while(i<n)
        {
            i = i*2;
        }
        return i==n;
    }
};
