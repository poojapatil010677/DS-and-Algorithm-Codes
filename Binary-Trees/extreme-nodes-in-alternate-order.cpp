/*

Extreme Nodes in alternate order

Given a binary tree, print nodes of extreme corners of each level but in 
alternate order.

*/

// method 1 

int height(Node* root)
{
    if(root==NULL) return 0;
    else
    {
        int l = height(root->left);
        int r = height(root->right);
        if(l>r) return l+1;
        return r+1;
    }
}

void printNode(Node* root,int h,int b,int* a)
{
    if(root==NULL) return;
    if(h==1 && *a==0)
    {
        cout << root->data <<' ';
        *a = *a + 1;
    }
    else
    {
        if(b==0)
        {
            printNode(root->left,h-1,b,a);
            printNode(root->right,h-1,b,a);
        }
        else
        {
            printNode(root->right,h-1,b,a);
            printNode(root->left,h-1,b,a);
        }
    }
}

void printExtremeNodes(Node* root)
{
    if(root==NULL) return;
    int h = height(root);
    for(int i=1;i<=h;i++)
    {
        int a = 0;
        printNode(root,i,i%2,&a);
    }
}

// method 2 (using queue)

void printExtremeNodes(Node* root)
{
    if(root==NULL) return;
    
    queue<Node*> q;
    q.push(root);
    int printright = 1;
    while(!q.empty())
    {
        if(printright)
            cout << q.back()->data << ' ';
        else
            cout << q.front()->data << ' ';
        int n = q.size();
        while(n--)
        {
            Node* curr = q.front();
            q.pop();
            
            if(curr->left!=NULL)
                    q.push(curr->left);
            if(curr->right!=NULL)
                    q.push(curr->right);
        }
        
        printright ^=1;
    }
}


