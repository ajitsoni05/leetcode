#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // Construct the graph
        vector<vector<int>> graph(n, vector<int>());
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        // Perform BFS
        queue<int> q;
        vector<bool> visited(n, false);
        q.push(source);
        visited[source] = true;

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            if (current == destination)
                return true;

            for (int neighbor : graph[current]) {
                if (!visited[neighbor]) {
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }

        return false;
    }
};
