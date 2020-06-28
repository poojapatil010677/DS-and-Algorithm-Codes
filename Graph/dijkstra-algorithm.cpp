/*

Implementing Dijkstra using adjacency Matrix

Given a graph of V nodes represented in the form of the adjacency matrix. 
The task is to find the shortest distance of all the vertex's from the source 
vertex.

ref : www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/

Expected Time Complexity: O(V2).
Expected Auxiliary Space: O(V).

*/

/*  Function to implement Dijkstra
*   g: vector of vectors which represents the graph
*   src: source vertex to start traversing graph with
*   V: number of vertices
*/

int minDistance(int* dist, bool* sptset,int V)
{
    int min_index,minm=INT_MAX;
    for(int i=0;i<V;i++)
    {
        if(sptset[i]==false && dist[i]<minm)
        {
            minm = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

vector <int> dijkstra(vector<vector<int>> g, int src, int V)
{
    int dist[V];
    bool sptset[V];
    
    for(int i=0;i<V;i++)
    {
        dist[i] = INT_MAX;
        sptset[i] = false;
    }
    
    dist[src] = 0;
    for(int i=0;i<V-1;i++)
    {
        int u = minDistance(dist,sptset,V);
        sptset[u] = true;
        
        for(int j=0;j<V;j++)
        {
            if(sptset[j]==false && g[u][j] && dist[u]!=INT_MAX && dist[u]+g[u][j]<dist[j])
            {
                dist[j] = dist[u] + g[u][j];
            }
        }
    }
    
    vector<int> res(V);
    for(int i=0;i<V;i++)
    {
        res[i] = dist[i];
    }
    return res;
}


