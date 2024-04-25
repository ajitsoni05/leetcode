class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        // Create a graph using adjacency list
        unordered_map<int, vector<pair<double, int>>> graph;

        for (int i = 0; i < edges.size(); i++) {
            graph[edges[i][0]].push_back({succProb[i], edges[i][1]});
            graph[edges[i][1]].push_back({succProb[i], edges[i][0]});
        }

        double maxProbability = 0.0;
        vector<bool> visited(n, false);
        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start});

        while (!pq.empty()) {
            auto [prob, node] = pq.top();
            pq.pop();
            
            if (visited[node]) continue; // Skip visited nodes
            visited[node] = true;
            
            if (node == end) {
                maxProbability = prob;
                break; // Early termination
            }
            
            for (auto [nextProb, neighbor] : graph[node]) {
                if (!visited[neighbor]) {
                    pq.push({prob * nextProb, neighbor});
                }
            }
        }

        return maxProbability;
    }
};
