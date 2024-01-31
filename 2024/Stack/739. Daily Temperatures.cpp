class Solution
{
public:
    // monotonic stack
    // see video codestorywithmik
    vector<int> dailyTemperatures(vector<int> &t)
    {
        int n = t.size();
        vector<int> ans(n);
        stack<int> st; // store index

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && t[i] >= t[st.top()]) // current bda from prev
                st.pop();

            if (st.empty())
                ans[i] = 0;
            else
                ans[i] = st.top() - i;

            st.push(i);
        }
        return ans;
    }
};