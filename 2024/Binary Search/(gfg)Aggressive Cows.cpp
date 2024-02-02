
class Solution
{
public:
    // 2.logic func
    bool solve(int n, int k, int dist, vector<int> &arr)
    {

        int cntcows = 1;
        int lastcow = arr[0];

        for (int i = 1; i < n; i++)
        {
            if (arr[i] - lastcow >= dist)
            {
                cntcows++;
                lastcow = arr[i];
            }
        }
        if (cntcows >= k)
            return true;
        return false;
    }
    int solve(int n, int k, vector<int> &stalls)
    {
        // 1.range
        // 1 to (max-min);
        sort(stalls.begin(), stalls.end());
        int maxi = stalls[n - 1];
        int mini = stalls[0];

        int s = 1;
        int e = maxi - mini;

        while (s <= e)
        {
            int mid = s + (e - s) / 2;

            if (solve(n, k, mid, stalls) == true)
                s = mid + 1;
            else
                e = mid - 1;
        }
        return e;
    }
};