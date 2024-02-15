class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &p)
    {
        // 1.
        sort(p.begin(), p.end());
        vector<int> prev = p[0]; // pehla start
        int cnt = 1;             // pehle me toh lgega hi

        for (int i = 1; i < p.size(); i++)
        {
            int currstart = p[i][0];
            int currend = p[i][1];

            int prevstart = prev[0];
            int prevend = prev[1];

            // 2.overlapping conditions
            if (prevend >= currstart) // overlapping
            {
                // find overlap region  [1,6](prev) , [2,8](curr)
                prev[0] = max(prevstart, currstart);
                prev[1] = min(prevend, currend);
                // ye new prev bn jaayega aur curr toh aage bdh hi rha
            }
            else // no overlap
            {
                cnt++;
                prev = p[i];
                // prev =curr hojaayega and curr toh bdh hi rha hai
            }
        }
        return cnt;
    }
};