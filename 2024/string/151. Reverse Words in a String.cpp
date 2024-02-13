class Solution
{
public:
    string reverseWords(string s)
    {
        // stringstream ss(s);
        // string token;
        // string ans;
        // while(ss>>token){  //ye yha pe bydefault string ko spaces se break krrk
        // //token me daalta jaayega
        // ans=token+" "+ans;
        // }
        // int n=ans.size();
        // return ans.substr(0,n-1); // to remove extra space at last

        //**********************Another Approach**********************
        string ans = "";
        string str = "";
        int n = s.size();

        for (int i = n - 1; i >= 0; i--)
        {
            if (str == "" && s[i] == ' ')
                continue;
            else if (s[i] == ' ')
            {
                reverse(str.begin(), str.end()); // words ko revesre krrk seedha eulb->blue
                ans += str;
                ans += " ";
                str = "";
            }
            else
                str += s[i];
        }
        // last word ;
        reverse(str.begin(), str.end()); // words ko revesre krrk seedha eulb->blue
        ans += str;

        int size = ans.size();

        if (ans[size - 1] == ' ') // if last me space aa skta hai
            return ans.substr(0, size - 1);
        else
            return ans;
    }
};