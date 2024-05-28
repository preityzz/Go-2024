class Solution
{
public:
    int equalSubstring(string s, string t, int maxcost)
    {
        int ans = 0;
        int maxi = INT_MIN;
        int i = 0;
        int j = 0;
        if (s == t)
            return s.size();

        while (j < s.size())
        {
            ans += abs(s[j] - t[j]);

            // if(ans<maxcost){
            //     maxi=max(maxi,(j-i+1));
            // }
            // else if(ans==maxcost){
            // maxi=max(maxi,(j-i+1));
            //      ans-=abs(s[i]-t[i]);
            //     i++;

            // }
            // else if(ans>maxcost){
            // ans-=abs(s[i]-t[i]);
            // i++;
            // }
            while (ans > maxcost)
            {
                ans -= abs(s[i] - t[i]);
                i++;
            }

            maxi = max(maxi, (j - i + 1));
            j++;
        }
        return maxi == INT_MIN ? 0 : maxi;
    }
};