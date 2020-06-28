/*

Bit Difference

You are given two numbers A and B. Write a program to count number of bits 
needed to be flipped to convert A to B.

Expected Time Complexity: O(log N).
Expected Auxiliary Space: O(1).

Input:
2
10 20
20 25
Output:
4
3

*/

int countBitsFlip(int a, int b){ 
    int count = 0;
    while(a || b)
    {
        if((a&1)!=(b&1)) count++;
        a = a>>1;
        b = b>>1;
    }
    return count;
}
