class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        // multi source BFS + binary search

        // mark all the grid elements as -1 and leave the thieves as 0

        int m = grid.size();
        int n = grid[0].size();

        // queue of pair to do bfs
        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)
                    q.push({i, j});
                else
                    grid[i][j] = -1;
            }
        }

        vector<pair<int, int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        // stat multi source bfs
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (auto [dx, dy] : dir) {
                int X = x + dx;
                int Y = y + dy;
                int val = grid[x][y];

                if (isValid(grid, X, Y) and grid[X][Y] == -1) {
                    grid[X][Y] = val + 1;
                    q.push({X, Y});
                }
            }
        }
        // collected all the distances

        // get the max ManHattan distance
        int maxD = INT_MIN;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                maxD = max(maxD, grid[i][j]);
            }
        }

        // time to apply binary seach
        int start = 0, end = maxD;

        int possibleAns = -1;

        if (grid[0][0] == 0 || grid[m - 1][n - 1] == 0)
            return 0;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (isValidMan(grid, mid)) {
                start = mid + 1;
                possibleAns = mid;
            } else {
                end = mid - 1;
            }
        }
        return possibleAns == -1 ? 0 : possibleAns-1;
    }
    bool isValidMan(vector<vector<int>>& g, int& manD) {
        int m = g.size();
        int n = g[0].size();

        if (g[0][0] < manD)
            return false; // ❗ Add this line

        queue<pair<int, int>> q;
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        q.push({0, 0});
        vis[0][0] = true;

        vector<pair<int, int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            if (x == m - 1 && y == n - 1)
                return true;

            for (auto [dx, dy] : dir) {
                int X = x + dx;
                int Y = y + dy;

                if (isValid(g, X, Y) && g[X][Y] >= manD && !vis[X][Y]) {
                    vis[X][Y] = true;
                    q.push({X, Y});
                }
            }
        }

        return false;
    }

    bool isValid(vector<vector<int>>& g, int x, int y) {
        int m = g.size();
        int n = g[0].size();

        if (x >= 0 and x < m and y >= 0 and y < n)
            return true;
        return false;
    }
};