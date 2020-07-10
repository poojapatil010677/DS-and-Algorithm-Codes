/*

Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a val (int) and a list (List[Node]) of its neighbors.

class Node {
    public int val;
    public List<Node> neighbors;
}
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        
        queue<Node*> q;
        unordered_map<Node*,Node*> m;
        
        Node* copy = new Node(node->val);
        m[node] = copy;
        
        q.push(node);
        while(!q.empty())
        {
            Node* curr = q.front();
            q.pop();
            vector<Node*> v = curr->neighbors;
            int n = v.size();
            for(int i=0;i<n;i++)
            {
                if(m[v[i]]==NULL)
                {
                    copy = new Node(v[i]->val);
                    m[v[i]] = copy;
                    q.push(v[i]);
                }
                
                m[curr]->neighbors.push_back(m[v[i]]);
            }
        }
        return m[node];
    }
};
