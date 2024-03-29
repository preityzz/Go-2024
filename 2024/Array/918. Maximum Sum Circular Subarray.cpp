class Solution
{
public:
    int maxSubarraySumCircular(vector<int> &nums)
    {
        /*
        Use Kaden's algorithm:

          1.find max_sum
         2. find min_sum
          3.find max of max_sum and total_sum - (-min_sum)
        */

        // 1.
        int sum = 0;
        int maxi = INT_MIN;
        int tot = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            tot += nums[i]; // total sum

            if (sum > maxi)
            {
                maxi = sum;
            }

            if (sum < 0)
                sum = 0;
        }
        // 2.
        int sum2 = 0;
        int mini = INT_MAX;

        for (int i = 0; i < nums.size(); i++)
        {
            sum2 += nums[i];

            if (sum2 < mini)
                mini = sum2;

            if (sum2 > 0)
                sum2 = 0;
        }

        // 3.
        if (maxi < 0)
            return maxi; // when all the elements are negative,
        return max(tot - mini, maxi);
    }
};