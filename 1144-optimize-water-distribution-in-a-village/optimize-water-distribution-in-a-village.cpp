#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        // Min heap: pair<cost, house>
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> edgesHeap;

        // Graph represented as an adjacency list: graph[u] = list of {cost, v}
        vector<vector<pair<int, int>>> graph(n + 1);

        // Add virtual edges from node 0 to all houses with well costs
        for (int i = 0; i < wells.size(); ++i) {
            graph[0].emplace_back(wells[i], i + 1);
            edgesHeap.emplace(wells[i], i + 1);
        }

        // Add bidirectional edges from the pipes
        for (const auto& pipe : pipes) {
            int house1 = pipe[0], house2 = pipe[1], cost = pipe[2];
            graph[house1].emplace_back(cost, house2);
            graph[house2].emplace_back(cost, house1);
        }

        // Prim's algorithm
        unordered_set<int> mstSet;
        mstSet.insert(0);

        int totalCost = 0;

        while (mstSet.size() < n + 1) {
            auto [cost, nextHouse] = edgesHeap.top();
            edgesHeap.pop();

            if (mstSet.count(nextHouse)) {
                continue;
            }

            mstSet.insert(nextHouse);
            totalCost += cost;

            for (const auto& [nextCost, neighbor] : graph[nextHouse]) {
                if (!mstSet.count(neighbor)) {
                    edgesHeap.emplace(nextCost, neighbor);
                }
            }
        }

        return totalCost;
    }
};
