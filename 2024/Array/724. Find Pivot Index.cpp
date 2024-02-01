// important concept
class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        //     int n=nums.size();
        //   vector<int> left(n);
        //   left[0]=0;
        //   for(int i=1;i<n;i++)
        //      left[i]=left[i-1]+nums[i-1];

        //      vector<int> right(n);
        //      right[n-1]=0;
        //      for(int i=n-2;i>=0;i--)
        //      right[i]=right[i+1]+nums[i+1];

        //      for(int i=0;i<n;i++){
        //      if(left[i]==right[i])
        //      return i;
        //      }
        //      return -1;

        //*****************************************************************

        // codestorywithmik
        // rightsum of that index = totalsum-leftsum-nums[i];
        //   nums = [1,7,3,6,5,6] tsum=28;
        //  leftsum=1+7+3=11;
        // rightsum for i=3 is 28-11+6=11;
        // ls==rs return i;

        int tsum = 0;

        for (auto it : nums)
            tsum += it;

        int leftsum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int rightsum = tsum - leftsum - nums[i];

            if (leftsum == rightsum)
                return i;

            leftsum += nums[i];
        }
        return -1;
    }
};