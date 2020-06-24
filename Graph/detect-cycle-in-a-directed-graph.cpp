/*

Detect Cycle

*/

bool cycleUtil(vector<int> adj[],int* visit, int* stack, int i)
{
    if(visit[i]==0)
    {
        visit[i] = 1;
        stack[i] = 1;
        
        for(int j=0;j<adj[i].size();j++)
        {
            if(visit[adj[i][j]]==0 && cycleUtil(adj,visit,stack,adj[i][j]))
                return true;
            else if(stack[adj[i][j]]) return true;
        }
        stack[i] = 0;
    }
    
    return false;
}

bool isCyclic(int V, vector<int> adj[])
{
    int visit[V] = {0};
    int stack[V] = {0};
    
    for(int i=0;i<V;i++)
    {
        if(cycleUtil(adj,visit,stack,i))
            return true;
    }
    return false;
    
}
