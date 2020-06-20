/*

Stock span problem

The stock span problem is a financial problem where we have a series of n daily price quotes for a stock and we need to calculate the span of stock’s price for all n days. 
The span Si of the stock’s price on a given day i is defined as the maximum number of consecutive days just before the given day, for which the price of the stock on the current day is less than or equal to its price on the given day.
For example, if an array of 7 days prices is given as {100, 80, 60, 70, 60, 75, 85}, then the span values for corresponding 7 days are {1, 1, 1, 2, 1, 4, 6}.

Input:
2
7
100 80 60 70 60 75 85
6
10 4 5 90 120 80
Output:
1 1 1 2 1 4 6
1 1 2 4 5 1

*/

vector <int> calculateSpan(int price[], int n)
{
   // Your code here
   vector<int> v(n);
   stack<int> s;
   for(int i=0;i<n;i++)
   {
       v[i] = 1;
       while(!s.empty() && s.top()<=price[i])
       {
           v[i]+= v[i-v[i]];
           s.pop();
       }
       s.push(price[i]);
   }
   return v;
}

