class Solution
{
public:
    vector<int> sequentialDigits(int low, int high)
    {
        string s = "123456789";

        vector<int> res;

        for (int i = 0; i < s.size(); i++)
        {
            string str = "";
            for (int j = i; j < s.size(); j++)
            {
                str += s[j];
                int n = stoi(str);
                if (n >= low && n <= high)
                    res.push_back(n);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};