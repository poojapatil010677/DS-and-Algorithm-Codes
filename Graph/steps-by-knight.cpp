/*

Steps by Knight

Given a square chessboard of N x N size, the position of Knight and position of a target is given. We need to find out minimum steps a Knight will 
take to reach the target position.

Time complexity : O(n^n)
space complexity : O(n^n)

BFS approach

*/

#include <iostream>
#include<string.h>
#include<queue>
using namespace std;

struct cell
{
    int x;
    int y;
    int dis;
    cell(){};
};

int findDistance(int kpos[],int tpos[],int n)
{
    bool visit[n+1][n+1];
    memset(visit,false,sizeof(visit));
    
    cell* c = new cell();
    queue<cell*> q;
    c->x = kpos[0];
    c->y = kpos[1];
    c->dis = 0;
    q.push(c);
    visit[kpos[0]][kpos[1]] =true;
    int distx[] = {-2,-1,1,2,1,2,-2,-1};
    int disty[] = {-1,-2,-2,-1,2,1,1,2};
    
    while(!q.empty())
    {
        cell* t = q.front();
        q.pop();
        
        if(t->x==tpos[0] && t->y==tpos[1])
            return t->dis;
        else
        {
            for(int i=0;i<8;i++)
            {
                if(t->x+distx[i]>0 && t->x+distx[i]<=n && t->y+disty[i]>0 && t->y+disty[i]<=n && !visit[t->x+distx[i]][t->y+disty[i]])
                {
                    cell* n = new cell();
                    n->x = t->x+distx[i];
                    n->y = t->y+disty[i];
                    n->dis = t->dis+1;
                    visit[n->x][n->y]=true;
                    q.push(n);
                }
            }
        }
    }
    return -1;
}

int main() {
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int kpos[2],tpos[2];
        scanf("%d %d",&kpos[0],&kpos[1]);
        scanf("%d %d",&tpos[0],&tpos[1]);
        int dis = findDistance(kpos,tpos,n);
        printf("%d\n",dis);
    }
	return 0;
}
