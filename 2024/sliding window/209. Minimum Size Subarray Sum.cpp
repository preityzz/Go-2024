class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int i = 0, j = 0;
        int sum = 0;
        int ans = nums.size() + 1;

        while (i < nums.size())
        {
            sum += nums[i];
            if (sum < target)
                i++;
            else
            {
                while (sum >= target)
                {
                    ans = min(ans, i - j + 1);
                    sum -= nums[j++];
                }
                i++;
            }
        }
        return ans == nums.size() + 1 ? 0 : ans;
    }
};