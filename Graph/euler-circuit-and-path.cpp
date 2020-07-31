/*

Euler circuit and path

Eulerian Path is a path in graph that visits every edge exactly once. Eulerian 
Circuit is an Eulerian Path which starts and ends on the same vertex. The task 
is to find that there exists the Euler Path or circuit or none in given undirected 
graph.

Input:
1
5 5
1 0 0 2 2 1 0 3 3 4
Output:
1

source : https://practice.geeksforgeeks.org/problems/euler-circuit-and-path/1

*/

int Graph::isEulerian()
{
    int count = 0;
    for(int i=0;i<V;i++)
    {
        if(adj[i].size()%2!=0)
            count++;
    }
    
    if(count==0) return 2;
    else if(count>2) return 0;
    else
    return 1;
}

