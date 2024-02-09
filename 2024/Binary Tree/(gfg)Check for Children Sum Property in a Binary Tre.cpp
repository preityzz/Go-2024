class Solution
{
public:
    int solve(Node *root)
    {
        // tc=O(n)
        // if node nul or leaf toh return 1
        if (root == NULL || (root->left == NULL && root->right == NULL))
            return 1;

        // nhi toh condition check
        else
        {
            int leftdata = 0, rightdata = 0;

            if (root->left)
                leftdata = root->left->data;

            if (root->right)
                rightdata = root->right->data;

            if ((leftdata + rightdata == root->data) && solve(root->left) && solve(root->right))
                return 1;
            else
                return 0;
        }
    }
    int isSumProperty(Node *root)
    {
        return solve(root);
    }
};