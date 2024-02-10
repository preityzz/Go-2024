class Solution
{
public:
    // tc=O(n^3)
    //  bool check(string &s,int i,int j){

    //     while(i<j){
    //         if(s[i]!=s[j])
    //         return false;
    //         i++;j--;

    //     }
    //     return true;
    // }
    //     int countSubstrings(string s) {
    // int cnt=0;

    // for(int i=0;i<s.size();i++){
    //     for(int j=i;j<=s.size();j++){
    //           if(check(s,i,j))
    //          cnt++;
    //     }
    // }

    // return cnt;

    // O(n^2)

    int dp[1001][1001];
    bool check(string &s, int i, int j)
    {
        if (i > j)
            return true;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == s[j])
            return dp[i][j] = check(s, i + 1, j - 1);

        return dp[i][j] = false;
    }
    int countSubstrings(string s)
    {

        memset(dp, -1, sizeof(dp));
        int cnt = 0;
        // O(n^2)
        for (int i = 0; i < s.size(); i++)
        {
            for (int j = i; j <= s.size(); j++)
            {
                if (check(s, i, j))
                    cnt++;
            }
        }

        return cnt;
        // another approach is also there which is dp
    }
};