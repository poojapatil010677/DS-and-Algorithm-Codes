/*

First Set Bit

Given an integer an N. The task is to print the position of first set bit 
found from the right side in the binary representation of the number.

Expected Time Complexity: O(log N).
Expected Auxiliary Space: O(1).

Example:
Input:
3
18
12
0

Output:
2
3
0

*/

unsigned int getFirstSetBit(int n){
    
    int count = 0;
    while(n)
    {
        count++;
        if(n&1) return count;
        n = n>>1;
    }
    return 0;
}
