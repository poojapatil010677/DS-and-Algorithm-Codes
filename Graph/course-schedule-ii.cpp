/*

Course schedule 2

There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

Example 1:

Input: 2, [[1,0]] 
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished   
             course 0. So the correct course order is [0,1] .
Example 2:

Input: 4, [[1,0],[2,0],[3,1],[3,2]]
Output: [0,1,2,3] or [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both     
             courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. 
             So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3] .

*/


class Solution {
public:
    vector<int> findOrder(int num, vector<vector<int>>& pre) {
        int n = num;
        int ind[n];
        memset(ind,0,sizeof(int)*n);
        vector<int> adj[n];
        for(int i=0;i<pre.size();i++)
        {
            adj[pre[i][1]].push_back(pre[i][0]);
            ind[pre[i][0]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++)
        {
         //   cout <<ind[i] <<' ';
            
            if(ind[i]==0)
            {
                num--;
                q.push(i);
            }
        }
        vector<int> res;
        while(!q.empty())
        {
            int temp = q.front();
            res.push_back(temp);
            q.pop();
            for(int i=0;i<adj[temp].size();i++)
            {
                ind[adj[temp][i]]--;
                if(ind[adj[temp][i]]==0)
                {
                    q.push(adj[temp][i]);
                    num--;
                }
            }
        }
        if(num!=0)
        {
            vector<int> res;
            return res;
        }
        return res;
    }
};
