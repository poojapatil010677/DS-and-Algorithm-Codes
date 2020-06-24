/*

Vertical Sum

Given a Binary Tree, find vertical sum of the nodes that are in same vertical line. Print all sums through different vertical lines starting from left-most vertical line to right-most vertical line.

*/

void sumUtil(Node* root, int hd, map<int,int>& m)
{
    if(root==NULL)
        return;
    if(m.find(hd)==m.end()) 
        m[hd] = root->data;
    else
        m[hd]+=root->data;
        
    sumUtil(root->left,hd-1,m);
    sumUtil(root->right,hd+1,m);
}

vector <int> verticalSum(Node *root) {
    
    vector<int> res;
    if(root==NULL) return res;
    
    map<int,int> m;
    sumUtil(root,0,m);
    
    for(auto it:m)
    {
        res.push_back(it.second);
    }
    return res;
}
