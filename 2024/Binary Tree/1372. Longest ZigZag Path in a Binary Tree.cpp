class Solution
{
public:
    // codestorywithmik tc=O(n)
    int maxans = 0;
    void solve(TreeNode *root, int left, int right)
    {
        if (root == NULL)
            return;

        // also aise bhi
        maxans = max({maxans, left, right});
        maxans = max(maxans, max(left, right));

        // left me jaa rhe h mtlb right se aaye h tohrightvaale steps me+1 krrdo(r+1,0)
        solve(root->left, right + 1, 0);
        // right me jaa rhe mtlb left se aaye h toh (0,l+1)
        solve(root->right, 0, left + 1);
    }

    int longestZigZag(TreeNode *root)
    {
        solve(root, 0, 0);
        return maxans;
    }