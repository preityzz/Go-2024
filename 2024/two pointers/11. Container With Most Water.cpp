class Solution
{
public:
    static bool comp(pair<int, int> a, pair<int, int> b)
    {
        return a.first > b.first || (a.first == b.first && a.second < b.second);
    }
    int maxArea(vector<int> &height)
    {
        int maxi = INT_MIN;
        vector<pair<int, int>> v;

        for (int i = 0; i < height.size(); i++)
            v.push_back({height[i], i});

        sort(v.begin(), v.end(), comp);

        while (!v.empty())
        {
            int t1 = v.top().first;
            int tind1 = v.top().second;
            pq.pop();

            int t2 = v.top().first;
            int tind2 = v.top().second;

            int area = t2 * (abs(tind1 - tind2));
            maxi = max(maxi, area);
        }
        return maxi;
    }
};