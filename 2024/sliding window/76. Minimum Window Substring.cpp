class Solution
{
public:
    // see video coddestorywithmik
    // imp qus
    string minWindow(string s, string t)
    {

        int n = s.length();
        if (t.length() > n)
            return "";
        // map to store freq of chars
        unordered_map<char, int> mp;

        for (auto it : t)
        {
            mp[it]++;
        }

        int i = 0, j = 0;
        int requiredcnt = t.length();
        int ans = INT_MAX;
        int start_i = 0;
        // i aage j piche
        while (i < n)
        {
            if (mp[s[i]] > 0)
            {
                requiredcnt--;
            }
            mp[s[i]]--;

            while (requiredcnt == 0)
            {
                // start shrinking the window means j++
                int currsize = i - j + 1;

                if (currsize < ans)
                {
                    ans = currsize;
                    start_i = j;
                }
                mp[s[j]]++;

                if (mp[s[j]] > 0)
                    requiredcnt++;

                j++;
            }
            i++;
        }

        return ans == INT_MAX ? "" : s.substr(start_i, ans);
    }
};