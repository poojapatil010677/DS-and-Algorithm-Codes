void topoUtil(vector<int> adj[],int* visited,stack<int>& s,int x)
{
    if(visited[x]==0)
    {
        visited[x]=1;
        for(int i=0;i<adj[x].size();i++)
        {
            if(visited[adj[x][i]]==0)
                topoUtil(adj,visited,s,adj[x][i]);
        }
        s.push(x);
    }
}

vector<int> topoSort(int V, vector<int> adj[]) {
    int visited[V] = {0};
    stack<int> s;
    for(int i=0;i<V;i++)
    {
        topoUtil(adj,visited,s,i);
    }
    
    vector<int> res(V);
    int i=0;
    while(!s.empty())
    {
        res[i++] = s.top();
        s.pop();
    }
    return res;
}

