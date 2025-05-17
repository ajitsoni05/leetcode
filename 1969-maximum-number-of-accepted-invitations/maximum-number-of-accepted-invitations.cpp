#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int maximumInvitations(vector<vector<int>>& grid) {
        int M = grid.size();
        int N = grid[0].size();
        unordered_map<int, int> matches; // key = girl, value = boy

        // DFS function to try to match a boy with a girl
        function<bool(int, unordered_set<int>&)> dfs = [&](int boy, unordered_set<int>& visited) {
            for (int girl = 0; girl < N; ++girl) {
                if (grid[boy][girl] && visited.find(girl) == visited.end()) {
                    visited.insert(girl);

                    if (matches.find(girl) == matches.end() || dfs(matches[girl], visited)) {
                        matches[girl] = boy;
                        return true;
                    }
                }
            }
            return false;
        };

        for (int boy = 0; boy < M; ++boy) {
            unordered_set<int> visited;
            dfs(boy, visited);
        }

        return matches.size();
    }
};
