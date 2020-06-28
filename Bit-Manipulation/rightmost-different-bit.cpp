/*

Rightmost different bit

Given two numbers M and N. The task is to find the position of rightmost 
different bit in binary representation of numbers.

Input:
2
11 9
52 4

Output:
2
5

*/

int posOfRightMostDiffBit(int m, int n)
{ 
    int count = 0;
    while(m || n)
    {
        count++;
        if((m&1)!=(n&1)) return count;
        m = m>>1;
        n = n>>1;
    }
    return -1;
    
}
