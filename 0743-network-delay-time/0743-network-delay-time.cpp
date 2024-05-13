class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Constructing the graph
        vector<vector<pair<int, int>>> graph(n + 1);
        for (const auto& time : times) {
            int from = time[0], to = time[1], weight = time[2];
            graph[from].emplace_back(to, weight);
        }
        
        // Initialize distances
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        
        // Priority queue for Dijkstra's algorithm
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        
        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();
            
            if (d > dist[node]) continue; // Skip outdated nodes
            
            for (const auto& edge : graph[node]) {
                int neighbor = edge.first;
                int neighborDist = edge.second + d;
                
                if (neighborDist < dist[neighbor]) {
                    dist[neighbor] = neighborDist;
                    pq.push({neighborDist, neighbor});
                }
            }
        }
        
        // Find the maximum distance
        int maxDist = *max_element(dist.begin() + 1, dist.end());
        
        return maxDist == INT_MAX ? -1 : maxDist;
    }
};
