/*

Clone a Binary Tree

Given a Binary Tree having random pointers clone the Binary Tree. The task is 
to complete the function cloneTree which take one argument the root of the tree 
to be copied and should return the root of the cloned tree.

*/

void createClone(Node* root,unordered_map<Node*,Node*>& m)
{
    if(root==NULL) return;
    else
    {
        Node* newnode = new Node(root->data);
        m[root] = newnode;
        createClone(root->left,m);
        createClone(root->right,m);
    }
}

void connectClone(Node* root, unordered_map<Node*, Node*>& m)
{
    if(root==NULL) return;
    else
    {
        Node* temp = m[root];
        temp->left = m[root->left];
        temp->right = m[root->right];
        connectClone(root->left,m);
        connectClone(root->right,m);
    }
}

Node* cloneTree(Node* root)
{
    if(root==NULL) return root;
    
    unordered_map<Node*,Node*> m;
    
    createClone(root,m);
    connectClone(root,m);
    
    return m[root];
    
}

