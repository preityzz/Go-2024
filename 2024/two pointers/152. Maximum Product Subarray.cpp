class Solution
{
public:
    // very easy h bss ekbaar front se multiply krrte jaao ekbaar back se multiply krrte jaao dono mese max hoga jo vo ans;
    int maxProduct(vector<int> &nums)
    {
        int maxi = INT_MIN;
        int prefix = 1, suffix = 1;

        for (int i = 0; i < nums.size(); i++)
        {

            if (prefix == 0) // if 0 ho jaa rha set to 1 again
                prefix = 1;
            if (suffix == 0)
                suffix = 1;

            prefix = prefix * nums[i];                   // front se
            suffix = suffix * nums[nums.size() - i - 1]; // back se

            maxi = max(maxi, max(prefix, suffix));
        }

        return maxi;
    }
};