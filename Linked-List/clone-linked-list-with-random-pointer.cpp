/*

clone a linked list with next and random pointer

You are given a Singly Linked List with N nodes where each node next pointing 
to its next node. You are also given M random pointers , where you will be 
given M number of pairs denoting two nodes a and b  i.e. a->arb = b.

*/

Node *copyList(Node *head) {
    if(head==NULL) return NULL;
    
    Node* orgn = head;
    Node* copy = NULL;
    
    unordered_map<Node*,Node*> m;
    
    while(orgn)
    {
        copy = new Node(orgn->data);
        m[orgn] = copy;
        orgn = orgn->next;
    }
    
    orgn = head;
    
    while(orgn)
    {
        copy = m[orgn];
        copy->next = m[orgn->next];
        copy->arb = m[orgn->arb];
        orgn = orgn->next;
    }
    
    copy = m[head];
    return copy;
    
}
