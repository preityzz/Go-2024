class Solution
{
public:
    // lvl order traversal bss queu me pair of node and level
    bool check(Node *root)
    {
        if (!root)
            return true;
        int same = -1;
        queue<pair<Node *, int>> q; // node,lvl
        q.push({root, 0});

        while (!q.empty())
        {
            int x = q.size();

            while (x--)
            {

                Node *temp = q.front().first;
                int lvl = q.front().second;
                q.pop();

                if (!temp->left && !temp->right)
                {
                    // first level
                    if (same == -1)
                        same = lvl;

                    // baaki k levels
                    else if (lvl != same)
                        return false;
                }

                if (temp->left)
                    q.push({temp->left, lvl + 1});

                if (temp->right)
                    q.push({temp->right, lvl + 1});
            }
        }
        return true;
    }
};