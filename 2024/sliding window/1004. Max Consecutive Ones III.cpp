class Solution
{
public:
    // easy->iko inc krrte jaao and if 0h toh k-- krrte jaao and if(k<0)a toh shrink
    // shuru kro but if(nums[j]==0)toh k++krrdo (ek 0 exclude hogyaa naa)and j++;
    // then iko inc krrte rho and find max
    int longestOnes(vector<int> &nums, int k)
    {
        int i = 0;
        int j = 0;

        int ans = INT_MIN;
        while (i < nums.size())
        {
            if (nums[i] == 0)
            {
                k--;
            }
            if (k < 0)
            {
                if (nums[j] == 0)
                    k++;
                j++;
            }
            i++;
            ans = max(ans, i - j);
        }
        return ans;
    }
};