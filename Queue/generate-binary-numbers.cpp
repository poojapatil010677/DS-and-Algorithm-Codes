/*

Generate Binary Numbers

Given a number N. The task is to generate and print all binary numbers with decimal values from 1 to N.

Example:
Input:
2
2
5
Output:
1 10
1 10 11 100 101

*/

vector<string> generate(ll n)
{
	// Your code here
	queue<string> q;
	q.push("1");
	
	vector<string> res(n);
	
	for(ll i=0;i<n;i++)
	{
	    res[i] = q.front();
	    q.push(q.front()+"0");
	    q.push(q.front()+"1");
	    q.pop();
	}
	return res;
}
