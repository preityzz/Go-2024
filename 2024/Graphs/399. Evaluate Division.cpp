// IMP QUS

class Solution
{
public:
    // a/b=2 -> a to b ka value 2 h edgeweight
    void dfs(string src, string des, unordered_map<string, vector<pair<string, double>>> &adj, unordered_set<string> &vis, double prod, double &ans)
    {
        if (vis.find(src) != vis.end()) // already vis toh return
            return;

        vis.insert(src); // mark visited

        if (src == des)
        {
            ans = prod;
            return;
        }

        for (auto p : adj[src])
        {
            string v = p.first;
            double val = p.second;

            dfs(v, des, adj, vis, prod * val, ans);
        }
    }
    vector<double> calcEquation(vector<vector<string>> &eq, vector<double> &values, vector<vector<string>> &queries)
    {
        // 1.adj list
        unordered_map<string, vector<pair<string, double>>> adj;

        for (int i = 0; i < values.size(); i++)
        {
            string u = eq[i][0];
            string v = eq[i][1];
            double val = values[i];

            adj[u].push_back({v, val});       // a/b h toh b/a bhi store krrlo
            adj[v].push_back({u, 1.0 / val}); // 1.0 for double
        }

        // 2.find src destination
        vector<double> res;

        for (auto it : queries)
        {
            string src = it[0];
            string des = it[1];

            double ans = -1.0;
            double prod = 1.0;

            if (adj.find(src) != adj.end()) // present hoga tbhi toh dfs chalyenge
            {
                // 3.dfs
                unordered_set<string> vis; // visited for each src des //each query k liye different
                dfs(src, des, adj, vis, prod, ans);
            }
            res.push_back(ans);
        }
        return res;
    }
};