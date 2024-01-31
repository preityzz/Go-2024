class Solution
{
public:
    // tc=o(N *log (max-min+1)

    bool possible(vector<int> &arr, int day, int m, int k)
    {

        int ans = 0, cnt = 0;

        for (int i = 0; i < arr.size(); i++)
        {

            if (arr[i] <= day)
                cnt++;
            else
            {
                ans += (cnt / k);
                cnt = 0;
            }
        }
        ans += (cnt / k);
        if (ans >= m)
            return true;
        return false;
    }

    int minDays(vector<int> &v, int m, int k)
    {
        int maxi = INT_MIN;
        int mini = INT_MAX;

        for (int i = 0; i < v.size(); i++)
        {
            maxi = max(maxi, v[i]);
            mini = min(mini, v[i]);
        }

        // convert to ll   if(m*k>v.size()) return -1;
        long long val = m * 1LL * k * 1LL;
        if (val > v.size())
            return -1;

        // linear search
        //  for(int i=mini;i<=maxi;i++){
        //      if(possible(v,i,m,k)==true)
        //      return i;
        //  }
        //      return -1;
        // binary search

        int s = mini;
        int e = maxi;

        while (s <= e)
        {
            int mid = s + (e - s) / 2;

            if (possible(v, mid, m, k) == true)
                e = mid - 1;
            else
                s = mid + 1;
        }
        return s;
    }
};