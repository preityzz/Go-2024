class Solution
{
public:
    // tc=nlogn
    // sc=0(n)
    vector<int> temp; // to avoid TLE Declare here
    // So it's not intialized for every merge call

    long long merge(int s, int m, int e, vector<int> &nums)
    {
        temp.clear();
        long long ctr = 0;

        int left = s;
        int right = m + 1;

        while (left <= m && right <= e)
        {
            if (nums[left] <= nums[right])
            {
                temp.push_back(nums[left]);
                left++;
            }
            else
            {
                ctr += (m - left + 1); // m+1 len of arr, left is the pos
                temp.push_back(nums[right]);
                right++;
            }
        }
        while (left <= m)
        {
            temp.push_back(nums[left]);
            left++;
        }
        while (right <= e)
        {
            temp.push_back(nums[right]);
            right++;
        }

        for (int i = s; i <= e; i++)
        {
            nums[i] = temp[i - s];
        }

        return ctr;
    }
    long long ms(int s, int e, vector<int> &nums)
    {
        long long ctr = 0;

        if (s >= e)
            return 0;
        int mid = s + (e - s) / 2;
        ctr += ms(s, mid, nums);
        ctr += ms(mid + 1, e, nums);
        // here is where 2 broken sorted arrays are there
        // s...mid , mid+1...e
        ctr += merge(s, mid, e, nums);
        return ctr;
    }

    long long solve(vector<int> &nums)
    {
        long long cnt = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] > nums[i + 1])
                cnt++;
        }
        return cnt;
    }

    bool isIdealPermutation(vector<int> &nums)
    {
        // for global inversion  use merge sort just one line change strivers video

        int N = nums.size();
        vector<int> vec(nums.begin(), nums.end());
        long long gcnt = ms(0, N - 1, vec); // Modification 3 (global cnt)
        long long lcnt = solve(nums);       //(local cnt)
        return gcnt == lcnt;
    }
};