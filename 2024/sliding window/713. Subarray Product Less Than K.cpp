class Solution
{
public:
    // sum and shrink concept
    // lc-2302,same as 713 prod ki jgh is sum ask hota(subarray sum less than k)
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        int i = 0, prod = 1;
        int ans = 0;

        if (k == 1)
            return 0;

        for (int j = 0; j < nums.size(); j++)
        {

            prod *= nums[j]; // if sum hota toh sum+=nums[i]

            while (prod >= k && i < nums.size())
                prod /= nums[i++]; //  if sum hota toh sum-=nums[i]

            if (prod < k)
                ans += j - i + 1;
        }
        return ans;
    }
};