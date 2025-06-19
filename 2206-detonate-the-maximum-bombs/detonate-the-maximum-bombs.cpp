class Solution {
public:
    void dfs(const vector<vector<int>>& adj, vector<bool>& visited,
             int& detonatedBombs, int node) {
        visited[node] = true;
        detonatedBombs++;

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(adj, visited, detonatedBombs, neighbor);
            }
        }
    }

    bool liesInside(int x, int y, int r, int px, int py) {
        long long dx = px - x;
        long long dy = py - y;
        return dx * dx + dy * dy <= 1LL * r * r;
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> adj(n);

        // Build the adjacency list
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j && liesInside(bombs[i][0], bombs[i][1], bombs[i][2],
                                         bombs[j][0], bombs[j][1])) {
                    adj[i].push_back(j);
                }
            }
        }

        int maxDetonated = 0;

        // Try starting DFS from each bomb
        for (int i = 0; i < n; ++i) {
            vector<bool> visited(n, false);
            int detonatedBombs = 0;
            dfs(adj, visited, detonatedBombs, i);
            maxDetonated = max(maxDetonated, detonatedBombs);
        }

        return maxDetonated;
    }
};
