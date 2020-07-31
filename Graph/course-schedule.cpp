/*

Course Schedule

There are a total of numCourses courses you have to take, labeled from 0 to 
numCourses-1.

Some courses may have prerequisites, for example to take course 0 you have 
to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it 
possible for you to finish all courses?

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false

*/

class Solution {
public:
    bool canFinish(int num, vector<vector<int>>& pre) {
        
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
        while(!q.empty())
        {
            int temp = q.front();
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
        return (num==0);
    }
};
