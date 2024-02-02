//***********************BOOK ALLOCATION********************************************
class Solution
{
public:
    // Function to find minimum number of pages.
    bool solve(int A[], int N, int pages, int M)
    {
        int cntstudent = 1;
        long long tpages = 0;

        for (int i = 0; i < N; i++)
        {
            if (tpages + A[i] <= pages)
            {
                tpages += A[i];
            }
            else
            {
                cntstudent++;
                tpages = A[i];
            }
        }
        // array me element bache hue h jo ki extra students ko mil gye
        // mtlb pages ki value badhao so that jayda pages mile km student ko i.e. s=mid+1;
        if (cntstudent > M)
            return true;
        return false;
    }
    int findPages(int A[], int N, int M)
    {
        if (M > N)
            return -1;
        // 1.range max to totalsum
        int maxi = *max_element(A, A + N);
        int tsum = accumulate(A, A + N, 0);

        int s = maxi;
        int e = tsum;

        while (s <= e)
        {
            int mid = s + (e - s) / 2;

            if (solve(A, N, mid, M) == true)
                s = mid + 1;
            else
                e = mid - 1;
        }
        return s;
    }
};