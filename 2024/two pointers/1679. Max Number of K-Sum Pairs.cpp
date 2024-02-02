class Solution
{
public:
    int maxOperations(vector<int> &nums, int k)
    {
        // 2 pointers
        //  int cnt=0;
        //  sort(nums.begin(),nums.end());
        //  int i=0;int j=nums.size()-1;
        //  while(i<j){
        //      if(nums[i]+nums[j]==k){
        //          cnt++;
        //          i++;j--;
        //      }
        //      else if(nums[i]+nums[j]>k)
        //      j--;
        //      else
        //      i++;

        // }
        // return cnt;

        // map se

        unordered_map<int, int> mp;
        int cnt = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            int a = nums[i];
            int b = k - a;

            if (mp[b] > 0)
            {
                cnt++;
                mp[b]--;
            }
            else
                mp[a]++;
        }
        return cnt;
    }
};