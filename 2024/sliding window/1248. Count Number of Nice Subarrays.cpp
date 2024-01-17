class Solution
{
public:
    // same qus as subaaray sum equals k bss change numss to array that is even->0 and odd->1 in arr.ans if sum of subaaray equal k then mtlb vo odd ka h .
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        vector<int> arr;

        for (auto it : nums)
        {
            if (it % 2 == 0)
                arr.push_back(0);
            else
                arr.push_back(1);
        }

        // subarray sum equals k
        int n = arr.size();
        unordered_map<int, int> mpp;
        int preSum = 0, count = 0;

        mpp[0] = 1;

        for (int i = 0; i < n; i++)
        {
            preSum += arr[i];
            int remove = preSum - k;
            count += mpp[remove];
            mpp[preSum]++;
        }

        return count;
    }
};