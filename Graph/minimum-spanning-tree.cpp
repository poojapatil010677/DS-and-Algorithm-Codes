/*

Minimum spanning Tree

Given a weighted, undirected and connected graph. The task is to find the sum 
of weights of the edges of the Minimum Spanning Tree.

Input:
2
3 3
1 2 5 2 3 3 1 3 1
2 1
1 2 5

Output:
4
5

Expected Time Complexity: O(V2).
Expected Auxiliary Space: O(V).

*/


// Function to construct and print MST for
// a graph represented using adjacency
// matrix representation, with V vertices.
// graph[i][j] = weight if edge exits else INT_MAX
int spanningTree(int V, int E, vector<vector<int>> &graph) {
    // code here
    int marked[V];
    memset(marked,0,sizeof(marked));
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    int minCost = 0;
    pq.push({0,0});
    while(!pq.empty())
    {
        pair<int,int> p = pq.top();
        pq.pop();
        int x = p.second;
        if(marked[x])
            continue;
        marked[x] = 1;
        minCost += p.first;
        for(int i=0;i<graph[x].size();i++)
        {
            if(graph[x][i]!=INT_MAX && marked[i]==0)
                pq.push({graph[x][i],i});
        }
    }
    return minCost;
}
