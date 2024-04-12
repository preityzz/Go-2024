class Solution
{
public:
    long long maximumTripletValue(vector<int> &nums)
    {
        // see video by coding samurai
        int n = nums.size();
        long long ans = INT_MIN;
        vector<int> s(n);
        vector<int> p(n);
        p[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            p[i] = max(p[i - 1], nums[i]);
        }
        s[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            s[i] = max(s[i + 1], nums[i]);
        }
        // curr element se pehle bda and current ele k baad bda
        for (int i = 1; i < n - 1; i++)
        {
            long long calc = (p[i - 1] - nums[i]) * 1ll * s[i + 1];
            ans = max(ans, calc);
        }

        return ans < 0 ? 0 : ans;
    }
};