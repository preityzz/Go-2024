class Solution
{
public:
    // very easy
    // find ans kispe milega yha pe boundary pe(i==0||i==m-1|| j==0||j==n-1 andi,j!=entrance)
    int nearestExit(vector<vector<char>> &maze, vector<int> &e)
    {
        int n = maze.size();
        int m = maze[0].size();

        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        q.push({{e[0], e[1]}, 0});
        vis[e[0]][e[1]] = 1;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        while (!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int steps = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m && maze[nr][nc] == '.' && vis[nr][nc] != 1)
                {

                    if (nr == 0 || nr == n - 1 || nc == 0 || nc == m - 1)
                        return steps + 1;

                    q.push({{nr, nc}, steps + 1});
                    vis[nr][nc] = 1;
                }
            }
        }
        return -1;
    }
};