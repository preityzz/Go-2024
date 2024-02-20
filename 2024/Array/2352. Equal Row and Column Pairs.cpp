class Solution
{
public:
    // 1. store the frequency of each row
    // 2. traverse and make vector for each col
    // 3. add ans+mp[col];
    int equalPairs(vector<vector<int>> &grid)
    {
        int cnt = 0;
        // 1.
        map<vector<int>, int> mp;

        for (int i = 0; i < grid.size(); i++)
            mp[grid[i]]++; // stored freq of each row

        for (int i = 0; i < grid[0].size(); i++)
        { // fix col and each row pe jaa rhe naa
            vector<int> col;
            for (int j = 0; j < grid.size(); j++)
            {
                col.push_back(grid[j][i]);
            }
            cnt = cnt + mp[col];
        }
        return cnt;
    }
};