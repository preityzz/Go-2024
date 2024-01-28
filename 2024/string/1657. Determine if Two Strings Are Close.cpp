class Solution
{
public:
    bool closeStrings(string word1, string word2)
    {
        // freq count yrr
        //  vo alphabets rehne chahiye jiske liye bool vector ans frequencies same rehni chahiye
        vector<int> f1(26, 0), f2(26, 0);
        vector<bool> p1(26, false), p2(26, false);

        for (auto it : word1)
        {
            f1[it - 'a']++;
            p1[it - 'a'] = true;
        }

        for (auto it : word2)
        {
            f2[it - 'a']++;
            p2[it - 'a'] = true;
        }

        sort(f1.begin(), f1.end());
        sort(f2.begin(), f2.end());

        return f1 == f2 && p1 == p2;
    }
};