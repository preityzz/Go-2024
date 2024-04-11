class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> ans;
        // if(p.length()>s.length())
        //   return ans;

        vector<int> a(26, 0); // s ki frequency
        vector<int> b(26, 0); // p ki frequency

        int i = 0;
        int j = 0;
        // p ki freq pehle set krrlo
        for (auto it : p)
            b[it - 'a']++;

        while (j < s.size())
        {
            a[s[j] - 'a']++;
            if (j - i + 1 == p.size())
            { // eueal h toh ans check
                if (a == b)
                    ans.push_back(i);
            }
            if (j - i + 1 < p.size())
            { // chota h toh aage bdho
                j++;
            }
            else
            { // length jyada hogya toh i++ kro shrink the window
                a[s[i] - 'a']--;
                i++;
                j++;
            }
        }
        return ans;
    }
};