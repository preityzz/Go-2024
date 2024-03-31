class Solution
{
public:
    int sw(vector<int> &nums, int k)
    {
        int i = 0;
        int j = 0;
        int cnt = 0;
        unordered_map<int, int> mp;

        while (j < nums.size())
        {
            mp[nums[j++]]++;

            while (mp.size() > k) // map me unique elements hi rehte unki freq inc hoti bss
            {
                mp[nums[i]]--;
                if (mp[nums[i]] == 0)
                    mp.erase(nums[i]);
                i++;
            }

            cnt += (j - i + 1); // ending at j subarray ka length bhi hota and no. of subarray end at j bhi hota
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        // standard sliding window template bss 1 pattern change ki k-(k-1);
        // total unique nikaalne k lliye total k - pehla ka k
        return sw(nums, k) - sw(nums, k - 1);
    }
};