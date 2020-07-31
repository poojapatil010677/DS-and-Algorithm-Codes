/*

Bridge edge in Graph

Given an undirected graph and an edge, the task is to find if the given edge 
is a bridge in graph, i.e., removing the edge disconnects the graph.

Expected Time Complexity: O(N + M).
Expected Auxiliary Space: O(N).

Input:

2
4 3
0 1 1 2 2 3
1 2
5 5
1 2 2 0 1 0 3 4 3 0
2 0

Output:

1
0

*/


void dfs(list<int> adj[],int i,bool visit[])
{
    visit[i] = true;
    //list<int> :: iterator itr;
    for(auto itr=adj[i].begin();itr!=adj[i].end();itr++)
    {
        if(visit[*itr]==false)
            dfs(adj,*itr,visit);
    }
}

bool isBridge(list<int> adj[], int V, int s, int e) {
    bool visit[V];
    memset(visit,false,sizeof(visit));
    int bef = 0;
    int aft = 0;
    for(int i=0;i<V;i++)
    {
        if(visit[i]==false)
        {
            dfs(adj,i,visit);
            bef++;
        }
    }
    adj[s].remove(e);
    adj[e].remove(s);
    memset(visit,false,sizeof(visit));
    for(int i=0;i<V;i++)
    {
        if(visit[i]==false)
        {
            dfs(adj,i,visit);
            aft++;
        }
    }
    if(bef==aft) return false;
    return true;
}
