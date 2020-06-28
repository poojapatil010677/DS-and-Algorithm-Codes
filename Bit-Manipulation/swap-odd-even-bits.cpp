/*

Swap all odd and even bits

Given an unsigned integer N. The task is to swap all odd bits with even bits. 
For example, if the given number is 23 (00010111), it should be converted to 
43(00101011). Here, every even position bit is swapped with adjacent bit on 
right side(even position bits are highlighted in binary representation of 23),
and every odd position bit is swapped with adjacent on left side.

Example:
Input:
2
23
2

Output:
43
1

Testcase 1: Binary representation of the given number is 00010111 after 
swapping 00101011 = 43 in decimal.
Testcase 2: Binary representation of the given number is 10 after 
swapping 01 = 1 in decimal.

*/

unsigned int swapBits(unsigned int n)
{
	
	unsigned int even_bits = n & 0xAAAAAAAA;
	unsigned int odd_bits = n & 0x55555555;
	
	even_bits = even_bits>>1;
	odd_bits = odd_bits<<1;
	
	return (even_bits | odd_bits);
	
}
