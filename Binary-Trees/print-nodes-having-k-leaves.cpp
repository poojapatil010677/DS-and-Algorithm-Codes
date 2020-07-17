/*

Given a binary tree and a integer value K, the task is to print all nodes data 
in given binary tree having exactly K leaves in sub-tree rooted with them. If no node is found then print -1.

NOTE: Nodes should be printed in the order in which they appear in postorder traversal.

Input:
2
1
0 1 2
2
0 1 2 N N 4 N 5 9

Output:
-1
4 2
*/

int printnodes(Node* root,int k,int& c)
{
    if(root==NULL) return 0;
    if(root->left==NULL && root->right==NULL)
        return 1;
    else
    {
        int l = printnodes(root->left,k,c);
        int r = printnodes(root->right,k,c);
        if(l+r==k)
        {
            cout << root->data <<' ';
            c++;
        }
        return l+r;
    }
}

void btWithKleaves(Node *root, int k)
{ 
    if(root==NULL) return;
    int c = 0;
    printnodes(root,k,c);
    if(c==0) 
    cout << -1<<' ';
    cout << '\n';
}
