/*

Print Top View of binary tree

*/

void topViewUtil(Node* root,int dist, int level, map<int,pair<int,int>>& m)
{
    if(root==NULL) return;
    
    if(m.find(dist)==m.end())
        m[dist] = {root->data,level};
    
    else if(level<m[dist].second)
    {
        m[dist] = {root->data,level};
    }
    
    topViewUtil(root->left,dist-1,level+1,m);
    topViewUtil(root->right,dist+1,level+1,m);
}

// function should print the topView of the binary tree
void topView(struct Node *root)
{
    //Your code here
    if(root==NULL) return;
    
    map<int,pair<int,int>> map;
    
    topViewUtil(root,0,0,map);
    for(auto it:map)
    {
        cout<<it.second.first<<' ';
    }
}


