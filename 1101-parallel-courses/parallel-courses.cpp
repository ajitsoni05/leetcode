class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        vector<int> indegree(n + 1, 0);
        vector<vector<int>> adj(n + 1);

        for (const auto& rel : relations) {
            int u = rel[0], v = rel[1];
            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        for (int i = 1; i <= n; ++i) {
            if (indegree[i] == 0) q.push(i);
        }

        int semesters = 0;
        int visitedCount = 0;

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                int node = q.front();
                q.pop();
                visitedCount++;
                for (int neighbor : adj[node]) {
                    if (--indegree[neighbor] == 0) {
                        q.push(neighbor);
                    }
                }
            }
            semesters++;
        }

        return visitedCount == n ? semesters : -1;
    }
};
