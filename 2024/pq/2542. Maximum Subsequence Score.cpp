class Solution
{
public:
    // imp and easy qus codestorywithmik
    long long maxScore(vector<int> &nums1, vector<int> &nums2, int k)
    {
        int n = nums1.size();
        vector<pair<int, int>> v(n); // nums1element,num2element

        for (int i = 0; i < n; i++)
        {
            v[i] = {nums1[i], nums2[i]};
        }
        // sorting ont the basis of second in descending order(nums2 ko sort krrliya
        //  usske corresponding nums1 k elelment aagye)

        auto lambda = [&](auto &P1, auto &P2)
        {
            return P1.second > P2.second;
        };

        sort(v.begin(), v.end(), lambda);

        priority_queue<int, vector<int>, greater<int>> pq; // min_heap

        // first k elements ka sum leliya
        long long Ksum = 0;

        for (int i = 0; i < k; i++)
        {

            Ksum += v[i].first;
            pq.push(v[i].first);
        }
        long long res = Ksum * v[k - 1].second; // abhi v[k-1].second min h

        // then traverse aage

        for (int i = k; i < n; i++)
        {
            // now v[i].second min h and to removE from Ksum we will exclude min from nums1 so that
            //  sum becomes max

            Ksum += v[i].first - pq.top();
            pq.pop();

            pq.push(v[i].first);

            res = max(res, Ksum * v[i].second);
        }
        return res;
    }
};