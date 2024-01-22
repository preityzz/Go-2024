class Solution
{
public:
    void solve(Node *root, int sum, int target, vector<int> &temp, vector<vector<int>> &ans)
    {

        if (root == nullptr)
        {
            return;
        }
        temp.push_back(root->key);

        if (target + root->key == sum)
            ans.push_back(temp);

        solve(root->left, sum, target + root->key, temp, ans);
        solve(root->right, sum, target + root->key, temp, ans);
        temp.pop_back();
    }
    vector<vector<int>> printPaths(Node *root, int sum)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(root, sum, 0, temp, ans);
        return ans;
    }
};