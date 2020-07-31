/*

Euler Circuit in a Directed Graph

Eulerian Path is a path in graph that visits every edge exactly once. Eulerian 
Circuit is an Eulerian Path which starts and ends on the same vertex. Your task 
is to find that their exists the Euler circuit or not.

Input:
1
5 6
1 0 0 2 2 1 0 3 3 4 4 0
Output:
1

*/

bool Graph::isEulerianCycle()
{
    int in[V],out[V];
    memset(in,0,sizeof(in));
    memset(out,0,sizeof(out));
    for(int i=0;i<V;i++)
    {
        out[i] = adj[i].size();
        for(auto it=adj[i].begin();it!=adj[i].end();it++)
        {
            in[*it]++;
        }
    }
    for(int i=0;i<V;i++)
    {
        if(in[i]!=out[i])
            return false;
    }
    return true;
}
