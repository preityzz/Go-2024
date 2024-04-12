class Solution
{
public:
    vector<int> goodDaysToRobBank(vector<int> &arr, int k)
    {
        // same qus as 2420
        int n = arr.size();
        vector<int> ans;
        vector<int> prefix(n);
        vector<int> suffix(n);

        prefix[0] = 0;
        suffix[n - 1] = 0;

        // prefix me dec order
        for (int i = 1; i < n; i++)
        {
            if (arr[i] <= arr[i - 1])
                prefix[i] = prefix[i - 1] + 1;
            else
                prefix[i] = 0;
        }

        // suffix me inc order
        for (int i = n - 2; i >= 0; i--)
        {
            if (arr[i] <= arr[i + 1])
                suffix[i] = suffix[i + 1] + 1;
            else
                // vo ele khud
                suffix[i] = 0;
        }

        // now if uss pos pe prefix/suffix ki val greater than k h mtlb enough inc and dec ele h
        for (int i = 0; i < n; i++)
        {
            if (prefix[i] >= k && suffix[i] >= k)
                ans.push_back(i);
        }
        return ans;
    }
};