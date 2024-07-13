class Solution
{
public:
    int minIncrementForUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        // qus 1827  same h bss sort ni krrna vha pe.
        int cnt = 0;

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i - 1] >= nums[i])
            {
                int val = (nums[i - 1] - nums[i] + 1);
                cnt += val;
                nums[i] = (nums[i] + val);
            }
        }
        return cnt;
    }
};