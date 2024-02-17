class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        stack<int> st;
        //  for collision always first ele +ve and second ele -ve
        // 2,-3 or 5,-4 -> <- bss
        for (auto &a : asteroids)
        {
            while (!st.empty() && a < 0 && st.top() > 0)
            {
                int sum = a + st.top();

                if (sum < 0)      // left side jaa rha 2,-5 =-3 toward left toh 2
                    st.pop();     // discard st.pop(); +ve hta toh st me se
                else if (sum > 0) // 10,-5 =5 toh right side jaayega +ve rhega
                    a = 0;        // set 0 toh while break hojaaega becoz a>0
                else              // sum==0
                {
                    st.pop();
                    a = 0;
                }
            }

            if (a != 0)
                st.push(a);
        }
        int n = st.size();
        vector<int> res(n);
        int i = n - 1;
        // no need to reverse the ans after taking from stack simply
        //  push from back index deke s.size()-1 se;
        while (!st.empty())
        {
            res[i] = st.top();
            st.pop();
            i--;
        }

        return res;
    }
};