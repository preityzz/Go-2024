class Solution
{
public:
    int minimumTimeToInitialState(string word, int k)
    {
        int n = word.size();

        // increase i by k at each step
        for (int i = 0; i < n; i += k)
        {

            // compare the remaining substring with the same length
            // of substring starting from 0
            if (i != 0 && word.substr(0, n - i) == word.substr(i, n - i))
            {
                // return number of steps which is i/k
                return i / k;
            }
        }
        // return maximum possible number of steps
        return ceil((double)n / k);
    }
};