/*

Power of four

Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

Example 1:

Input: 16
Output: true
Example 2:

Input: 5
Output: false

*/

class Solution {
public:
    bool isPowerOfFour(int num) {
     if(num<=0 || (num&(num-1))) return false;
     int n = log2(num);
     int m = n/2;
     cout<<n<<' '<<m;
        if(m*2==n) return true;
        return false;
    }
};
