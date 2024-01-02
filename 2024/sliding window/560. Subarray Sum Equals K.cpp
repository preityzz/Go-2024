class Solution
{
public:
    // same qus  as
    // Two Sum
    // Continuous Subarray Sum
    // Subarray Product Less Than K
    // Find Pivot Index
    // Subarray Sums Divisible by K
    // Minimum Operations to Reduce X to Zero
    // K Radius Subarray Averages
    int subarraySum(vector<int> &nums, int k)
    {
        //    int sum=0,n=nums.size();
        //   int count=0;
        //       unordered_map<int,int> prevsum;

        //       for(int i=0;i<n;i++){

        //           sum+=nums[i];

        //           if(sum==k)
        //           count++;

        //           if(prevsum.find(sum-k)!=prevsum.end())
        //           count+=prevsum[sum-k];

        //           prevsum[sum]++;

        //       }
        //       return count;

        int n = nums.size();
        unordered_map<int, int> mpp;
        int preSum = 0, count = 0;

        mpp[0] = 1;

        for (int i = 0; i < n; i++)
        {
            preSum += nums[i];
            int remove = preSum - k;
            count += mpp[remove];
            mpp[preSum]++;
        }

        return count;
    }
};