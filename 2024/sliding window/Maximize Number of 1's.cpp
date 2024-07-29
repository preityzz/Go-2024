// m is maximum of number zeroes allowed to flip
// n is size of array
// longest subarray with atmost k zeroes(sliding window concept qus h  )
int findZeroes(int arr[], int n, int m)
{

    int ans = INT_MIN;
    int i = 0;
    int j = 0;

    while (j < n)
    {

        if (arr[j] == 0)
        {
            m--;
            while (m < 0)
            {
                if (arr[i] == 0)
                    m++;

                i++;
            }
        }
        ans = max(ans, j - i + 1);
        j++;
    }
    return ans;
}
}
;