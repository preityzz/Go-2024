class Solution
{
public:
    int maxSubarrayLength(vector<int> &nums, int k)
    {
        int ans = INT_MIN;
        int n = nums.size();
        if (k == 0)
            return 0;
        int i = 0;
        int j = 0;
        unordered_map<int, int> mp;
        while (j < n)
        {
            int cur = nums[j++];
            mp[cur]++;
            while (i < j && mp[cur] > k)
            {
                mp[nums[i]]--;
                i++;
            }
            ans = max(ans, (j - i));
        }
        return ans;
    }
};