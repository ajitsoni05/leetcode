class Solution {
public:
    void dfs(vector<vector<int>>& adj, int src, vector<bool>& vis, int& count) {
        vis[src] = true;
        count++;

        for (auto nb : adj[src]) {
            if (!vis[nb]) {
                dfs(adj, nb, vis, count);
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        // size of each components and multiply them in pair and add it up

        // create an adjacency list
        vector<vector<int>> adj(n);

        // visited array
        vector<bool> vis(n, false);

        for (int i = 0; i < edges.size(); i++) {

            int v1 = edges[i][0];
            int v2 = edges[i][1];

            adj[v1].push_back(v2);
            adj[v2].push_back(v1);
        }

        vector<int> sizes;

        long long ans = 0;
        long long tot = 0;
        // dfs
        for (int i = 0; i < n; i++) {
            int count = 0;
            if (!vis[i])
                dfs(adj, i, vis, count);

            ans += tot * count;
            tot += count;
            sizes.push_back(count);
        }

        // for(int i = 0; i < sizes.size();i++){
        //      for(int j = 0; j < sizes.size();j++){
        //     if(i!=j)
        //     ans += (long)sizes[i]*((long)sizes[j]);
        // }
        // }
        return ans;
    }
};