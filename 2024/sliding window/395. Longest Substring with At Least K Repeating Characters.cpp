class Solution
{
public:
    int longestSubstring(string s, int k)
    {
        // Find the first character with frequency less than k using a while
        // loop that iterates through s.
        // If all char have valid freq -> return s.length();
        // Otherwise, split the substring in 2 parts : left part
        // from beginning of string to the first invalid char & right
        // part from the first invalid char to the end of the string.
        // Recursively call longestSubstring function on both parts to find
        // the longest valid substring.
        int n = s.length();
        unordered_map<char, int> mp;

        for (auto it : s)
            mp[it]++;

        int i = 0;
        while (i < n && mp[s[i]] >= k)
            i++;

        if (i == n)
            return n;
        int left = longestSubstring(s.substr(0, i), k);
        while (i < n && mp[s[i]] < k)
            i++;

        int right = (i < n) ? longestSubstring(s.substr(i), k) : 0;

        return max(left, right);
    }
};