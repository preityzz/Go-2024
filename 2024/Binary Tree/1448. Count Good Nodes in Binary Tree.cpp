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
    int cnt = 0;

    void inorder(TreeNode *root, int max)
    {
        // always base case
        if (root == nullptr)
            return;
        // condition case
        if (root->val >= max)
        {
            cnt++;
            max = root->val;
        }

        // fir left right
        inorder(root->left, max);
        inorder(root->right, max);
    }
    int goodNodes(TreeNode *root)
    {

        inorder(root, root->val);
        return cnt;
    }
};