class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        // bfs

        // create an adjacency list
        vector<vector<pair<int, int>>> adj(n);

        // flights
        for (auto f : flights) {
            adj[f[0]].emplace_back(f[1], f[2]);
        }

        // queue for bfs
        queue<pair<int, int>> q;

        // dist array
        vector<int> distance(n, INT_MAX);

        distance[src] = 0;

        q.push({src, 0});

        int stops = 0;

        while (!q.empty() && stops <= k) {
            int size = q.size();

            for (int i = 0; i < size; i++) {

                pair<int, int> ele = q.front();

                int dist = ele.second;
                int node = ele.first;

                q.pop();
                for (auto nb : adj[node]) {

                    int ngb = nb.first;
                    int cost = nb.second;

                    if (distance[ngb] > cost + dist) {
                        distance[ngb] = min(distance[ngb], cost + dist);
                        q.push({ngb, distance[ngb]});
                    }
                }
            }
            stops++;
        }

        return distance[dst] == INT_MAX ? -1 : distance[dst];
    }
};