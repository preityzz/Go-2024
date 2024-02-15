class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &a)
    {
        // 1.
        sort(a.begin(), a.end());
        // 2.
        int i = 0;
        int j = 1;
        int cnt = 0;
        while (j < a.size())
        {
            // overlap
            if (a[i][1] > a[j][0])
            {
                if (a[i][1] > a[j][1])
                { // toh i delete [cs,ce]
                    i = j;
                    j++;
                }
                else
                { // j delete [ns,ne]
                    j++;
                }
                cnt++;
            }
            else // no overlap
            {
                i = j;
                j++;
            }
        }
        return cnt;
    }
};