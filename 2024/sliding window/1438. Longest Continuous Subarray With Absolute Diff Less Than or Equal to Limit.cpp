class Solution
{
public:
    // ek qus sliding window + queue vaale type bhi hota h.
    int longestSubarray(vector<int> &nums, int limit)
    {

        priority_queue<pair<int, int>> pq;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq1;
        int ans = 0;

        int i = 0, j = 0;
        while (i < nums.size())
        {
            pq.push({nums[i], i});
            pq1.push({nums[i], i});
            while (!pq.empty() && pq.top().second < j)
                pq.pop();
            while (!pq1.empty() && pq1.top().second < j)
                pq1.pop();

            if ((abs(pq.top().first - pq1.top().first)) <= limit)
                ans = max(ans, i - j + 1);
            else
                j++;

            i++;
        }
        return ans;
    }
};