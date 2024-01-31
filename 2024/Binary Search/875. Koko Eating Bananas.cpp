class Solution
{
public:
    // easy
    // for binary search always look for range and some pattern as sorted inc or dec or asking for min and all
    // tc= o(n)*log(max(piles))

    long long int solve(vector<int> &piles, int k)
    {

        long long int ans = 0;
        for (int i = 0; i < piles.size(); i++)
        {
            ans += ceil((double)piles[i] / (double)k);
        }
        return ans;
    }

    int maxi(vector<int> &piles)
    {
        int maxii = INT_MIN;
        for (int i = 0; i < piles.size(); i++)
        {
            maxii = max(maxii, piles[i]);
        }
        return maxii;
    }
    int minEatingSpeed(vector<int> &piles, int h)
    {
        // we can take 1 to max(piles ) range
        int s = 1;
        int e = maxi(piles);

        while (s <= e)
        {
            int mid = s + (e - s) / 2;

            long long int totalhrs = solve(piles, mid);
            if (totalhrs <= h)
            {
                e = mid - 1;
            }
            else
                s = mid + 1;
        }

        return s;
    }
};