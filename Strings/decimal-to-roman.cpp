/*

Convert to Roman No 

Given an integer n, your task is to complete the function convertToRoman which prints the corresponding roman number of n. Various symbols and their values are given below.

I 1
V 5
X 10
L 50
C 100
D 500
M 1000

*/


// n :given number that you are require to convert
void convertToRoman(int n) 
{
    int nums[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
    string sym[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
    
    int i=12;
    
    while(n>0)
    {
        int d = n/nums[i];
        n = n%nums[i];
        
        while(d--)
        {
            cout << sym[i];
        }
        i--;
    }
}
