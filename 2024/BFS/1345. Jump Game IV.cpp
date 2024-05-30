class Solution
{
public:
    // simple h bhott simple bfs with conditions given
    int n;
    // bfs (bcoz asked min h issliye)
    // tc =O(n) aal elements ko sirf ek baar visist kr rhe due to vis aaray
    int minJumps(vector<int> &arr)
    {
        n = arr.size();
        unordered_map<int, vector<int>> mp; // for this cond ->j where: arr[i] == arr[j] and i != j.

        for (int i = 0; i < n; i++)
        {
            mp[arr[i]].push_back(i);
        }

        queue<int> q; // me hm index daal rhe kyunki vhii toh compare krrna
        vector<int> vis(n, 0);
        int jump = 0;

        q.push(0);
        vis[0] = 1;

        while (!q.empty())
        {
            int x = q.size();
            while (x--)
            {

                int ind = q.front();
                q.pop();

                if (ind == n - 1)
                    return jump;

                int left = ind - 1;  // i-1 k lie
                int right = ind + 1; // i+1 k liye

                if (left >= 0 && !vis[left])
                {
                    vis[left] = 1;
                    q.push(left);
                }

                if (right < n && !vis[right])
                {
                    vis[right] = 1;
                    q.push(right);
                }

                // now j where: arr[i] == arr[j] and i != j.
                for (auto it : mp[arr[ind]])
                {
                    if (!vis[it])
                    {
                        q.push(it);
                        vis[it] = 1;
                    }
                }

                mp.erase(arr[ind]); // taaki vaaps se uss ele k saare indices naa chle jaaye queue me
            }
            jump++;
        }
        return jump;
    }
};