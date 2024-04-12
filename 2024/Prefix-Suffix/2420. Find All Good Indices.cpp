class Solution
{
public:
    vector<int> goodIndices(vector<int> &arr, int k)
    {
        // same qus as 2100
        int n = arr.size();
        vector<int> ans;
        vector<int> prefix(n);
        vector<int> suffix(n);

        prefix[0] = 1;
        suffix[n - 1] = 1;

        // prefix me dec order
        for (int i = 1; i < n; i++)
        {
            if (arr[i] <= arr[i - 1])
                prefix[i] = prefix[i - 1] + 1;
            else
                prefix[i] = 1;
        }

        // suffix me inc order
        for (int i = n - 2; i >= 0; i--)
        {
            if (arr[i] <= arr[i + 1])
                suffix[i] = suffix[i + 1] + 1;
            else
                // vo ele khud
                suffix[i] = 1;
        }

        // now if uss pos pe prefix/suffix ki val greater than k h mtlb enough inc and dec ele h
        for (int i = k; i < n - k; i++)
        {
            if (prefix[i - 1] >= k && suffix[i + 1] >= k)
                ans.push_back(i);
        }
        return ans;
    }
};