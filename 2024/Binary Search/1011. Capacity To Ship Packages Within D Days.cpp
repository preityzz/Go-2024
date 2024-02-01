// binary search me bss 2 chizein
// 1.range for start and end
// 2.int solve() function for the logic
//  bss if logic h true toh for min find k liye e=mid-1;
//  max find k liye s=mid+1;

class Solution
{
public:
    // 2
    int solve(vector<int> &w, int capacity, int days)
    {
        // at day 1 load is 0;
        int day = 1;
        int load = 0;

        for (int i = 0; i < w.size(); i++)
        {
            if (w[i] + load > capacity)
            {
                day = day + 1;
                load = w[i];
            }
            else
                load += w[i];
        }

        if (day <= days)
            return true;
        return false;
    }
    int shipWithinDays(vector<int> &weights, int days)
    {
        // 1. range bt max weight and tsum me

        int s = *max_element(weights.begin(), weights.end());
        int e = accumulate(weights.begin(), weights.end(), 0);

        while (s <= e)
        {
            int mid = s + (e - s) / 2;

            if (solve(weights, mid, days) == true)
                e = mid - 1;
            else
                s = mid + 1;
        }
        return s;
    }
};