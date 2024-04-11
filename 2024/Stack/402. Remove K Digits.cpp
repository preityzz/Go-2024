class Solution
{
public:
    string removeKdigits(string s, int k)
    {
        // 1.  //using stack (monotonic stack)
        // 2.  //using string (string also works as stack)

        string ans = "";
        stack<char> st;
        int n = s.size();

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && st.top() > s[i] && k > 0)
            {
                st.pop();
                k--;
            }

            // normal h //Remove leading zeros
            if (!st.empty() || s[i] != '0')
                st.push(s[i]);
        }

        // k>0 h abhii bhi
        // toh bde no. ko htao peeche se kyuki inc order me h 12345 remove 345
        while (!st.empty() && k > 0)
        {
            st.pop();
            k--;
        }

        if (st.size() == 0)
            return "0";

        // int l=st.size();

        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};