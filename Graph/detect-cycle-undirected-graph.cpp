bool cycleUtil(vector<int> adj[],int* visit, int* stack, int i,int parent)
{
    if(visit[i]==0)
    {
        visit[i] = 1;
        stack[i] = 1;
        
        for(int j=0;j<adj[i].size();j++)
        {
            if(adj[i][j]!=parent)
            {
            if(visit[adj[i][j]]==0 && cycleUtil(adj,visit,stack,adj[i][j],i))
                return true;
            else if(stack[adj[i][j]]) return true;
            }
        }
        stack[i] = 0;
    }
    
    return false;
}

bool isCyclic(vector<int> adj[],int V)
{
    int visit[V] = {0};
    int stack[V] = {0};
    
    for(int i=0;i<V;i++)
    {
        if(cycleUtil(adj,visit,stack,i,-1))
            return true;
    }
    return false;
    
}
