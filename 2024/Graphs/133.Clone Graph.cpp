
// using dfs

class Solution
{
public:
    unordered_map<Node *, Node *> mp; //<original node,clone_node>

    void dfs(Node *node, Node *clone_node)
    {

        for (Node *n : node->neighbors)
        {
            if (mp.find(n) == mp.end())
            { // node is not visited yet toh bnao new and store

                Node *clone = new Node(n->val);
                mp[n] = clone;
                clone_node->neighbors.push_back(clone);
                dfs(n, clone);
            }
            else
            {
                clone_node->neighbors.push_back(mp[n]); // already clone node bn rkhi h
            }
        }
    }
    Node *cloneGraph(Node *node)
    {
        if (node == nullptr)
            return NULL;
        // 1. first node ka clone
        Node *clone_node = new Node(node->val);

        // 2.Now clone its neighbours and recursively their neighbours
        /*but if vo node already visited or cloned h then no need to clone that node
        simply move to the neighbors
        */

        mp[node] = clone_node; // node me clone node stored in map
        dfs(node, clone_node);
        return clone_node;
    }
};