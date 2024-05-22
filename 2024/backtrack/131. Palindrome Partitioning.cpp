class Solution
{
public:
    bool check(string s)
    {
        int i = 0;
        int j = s.size() - 1;
        while (i < j)
        {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    void solve(int pos, string s, vector<vector<string>> &ans, vector<string> &v)
    {
        if (pos == s.size())
        {
            ans.push_back(v);
            return;
        }

        for (int i = 1; i + pos <= s.size(); i++)
        {
            string str = s.substr(pos, i);
            if (check(str))
            {
                v.push_back(str);
                solve(pos + i, s, ans, v);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ans;
        vector<string> v;
        solve(0, s, ans, v);
        return ans;
    }
};
