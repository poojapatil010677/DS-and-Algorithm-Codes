/*

Vertical traversal of binary tree

Given a Binary Tree, print the vertical traversal of it starting from the 
leftmost level to the rightmost level.
If there are multiple nodes passing through a vertical line, then they should 
be printed as they appear in level order traversal of the tree.

Input:
3
2 N 3 4 N
1 2 3 4 5 N 6
3 1 5 N 2 4 7 N N N N 6 
Output:
2 4 3
4 2 1 5 3 6
1 3 2 4 5 6 7

*/

vector<int> verticalOrder(Node *root)
{
    vector<int> res;
    multimap<int,int> m;
    queue<pair<Node*,int>> q;
    q.push(make_pair(root,0));
    while(!q.empty())
    {
        pair<Node*,int> p = q.front();
        q.pop();
        m.insert(make_pair(p.second,p.first->data));
        if(p.first->left!=NULL)
            q.push(make_pair(p.first->left,p.second-1));
        if(p.first->right!=NULL)
            q.push(make_pair(p.first->right,p.second+1));
    }
    
    multimap <int,int> :: iterator itr;
    for(itr=m.begin();itr!=m.end();itr++)
    {
        res.push_back(itr->second);
    }
    return res;
}


