/*

Given a binary tree, you need to find the number of all root to leaf paths along with their path lengths.

*/

void help(Node* root,map<int,int>& m,int h)
{
    if(root==NULL) return;
    if(root->left==NULL && root->right==NULL)
        m[h]++;
    else
    {
        help(root->left,m,h+1);
        help(root->right,m,h+1);
    }
}

void pathCounts(Node *root)
{
    if(root==NULL) return;
    map<int,int> m;
    help(root,m,1);
    map<int,int> :: iterator itr;
    for(itr=m.begin();itr!=m.end();itr++)
    {
        cout << itr->first <<' '<<itr->second<<' '<<"$";
    }
}
