/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    bool isEvenOddTree(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);

        bool even_level = true; // start from 0 which is even

        while (!q.empty())
        {
            int x = q.size();

            int prev;
            if (even_level) // if even h toh in inc order
                prev = INT_MIN;

            else // if odd h toh in dec order
                prev = INT_MAX;

            while (x--)
            {
                auto curr = q.front();
                q.pop();

                // conditions
                if (even_level && (curr->val % 2 == 0 || prev >= curr->val))
                    return false;

                if (!even_level && (curr->val % 2 == 1 || prev <= curr->val))
                    return false;

                prev = curr->val; // update krrte chlo

                if (curr->left)
                    q.push(curr->left);

                if (curr->right)
                    q.push(curr->right);
            }
            // change if odd h toh even h toh odd
            even_level = !even_level;
        }
        return true;
    }
};