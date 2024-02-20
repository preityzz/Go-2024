class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        // take prefix product and then take suffix product
        // and multiply both of them
        vector<int> ans(nums.size(), 1);
        int prefix = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            ans[i] = prefix; // yha pe store
            prefix = prefix * nums[i];
        }
        int postfix = 1;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            ans[i] *= postfix; // yha pe jo store usse hi multiply
            postfix = postfix * nums[i];
        }
        return ans;
    }
};