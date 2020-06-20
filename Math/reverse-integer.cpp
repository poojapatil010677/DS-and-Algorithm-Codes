/*

Reverse Integer

Given a 32-bit signed integer, reverse digits of an integer.

*/

class Solution {
public:
int reverse(int x) {
if(x==0) return 0;
long long rev=0;
while(x!=0)
{
rev=rev*10+x%10;
x/=10;
}
if(rev>INT_MAX||rev<INT_MIN) return 0;
return (int)rev;
return rev;
}
};
