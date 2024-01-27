class Solution
{
public:
    int maxVowels(string s, int k)
    {
        int j = 0;
        int cnt = 0;
        int ans = INT_MIN;

        // pehle k  ke vowels cnt krrlo
        for (int i = 0; i < k; i++)
        {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
                cnt++;
        }

        ans = max(ans, cnt);
        // then slide krte jaao piche se - ans aage se +
        for (int i = k; i < s.size(); i++)
        {
            if (s[i - k] == 'a' || s[i - k] == 'e' || s[i - k] == 'i' || s[i - k] == 'o' || s[i - k] == 'u')
                cnt--;

            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
                cnt++;

            ans = max(ans, cnt);
        }
        return ans;
    }
};