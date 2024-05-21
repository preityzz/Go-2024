class Solution
{
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        vector<int> ans;
        int n = arr.size();

        /* //1.using pq
            priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>>q;

            for(int i=0 ; i<n ; i++)
            {
                q.push({abs(x-arr[i]) , arr[i]});
            }

            while(k--)
            {
                ans.push_back(q.top().second);
                q.pop();
            }

            sort(ans.begin() , ans.end());

            return ans;
            */

        // 2. using 2 pointers
        int l = 0;
        int r = n - 1;

        while (r - l >= k)
        {

            if (abs(arr[l] - x) > abs(arr[r] - x))
                l++;
            else
                r--;
        }

        while (l <= r)
        {
            ans.push_back(arr[l]);
            l++;
        }
        return ans;
    }
};