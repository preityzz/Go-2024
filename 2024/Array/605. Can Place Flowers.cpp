class Solution
{
public:
    bool canPlaceFlowers(vector<int> &f, int n)
    {
        if (n == 0)
            return true;

        int size = f.size();
        int cnt = 0;

        for (int i = 0; i < size; i++)
        {
            if (f[i] == 0)
            {
                int left = (i == 0) || (f[i - 1] == 0);
                int right = (i == size - 1) || (f[i + 1] == 0);

                if (left && right)
                {
                    cnt++;
                    f[i] = 1;

                    if (cnt >= n)
                        return true;
                }
            }
        }
        return false;
    }
};