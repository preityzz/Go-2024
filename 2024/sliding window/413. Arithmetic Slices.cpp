class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        int cnt = 0;
        int ans = 0;
        int n = nums.size();

        for (int i = 2; i < n; i++)
        {
            if (nums[i - 1] - nums[i - 2] == nums[i] - nums[i - 1])
            {
                cnt++;
                continue;
            }
            else
            {
                ans += (cnt * (cnt + 1) / 2);
                cnt = 0;
            }
        }
        ans += (cnt * (cnt + 1) / 2);
        return ans;
    }
};