class Solution {
public:
    bool dfs(int boy, vector<vector<int>>& grid, vector<bool>& visited, vector<int>& matchTo) {
        int n = grid[0].size(); // number of girls
        for (int girl = 0; girl < n; ++girl) {
            if (grid[boy][girl] == 1 && !visited[girl]) {
                visited[girl] = true;
                if (matchTo[girl] == -1 || dfs(matchTo[girl], grid, visited, matchTo)) {
                    matchTo[girl] = boy;
                    return true;
                }
            }
        }
        return false;
    }

    int maximumInvitations(vector<vector<int>>& grid) {
        int m = grid.size();    // number of boys
        int n = grid[0].size(); // number of girls

        vector<int> matchTo(n, -1); // matchTo[j] = i means girl j is matched to boy i
        int result = 0;

        for (int boy = 0; boy < m; ++boy) {
            vector<bool> visited(n, false);
            if (dfs(boy, grid, visited, matchTo)) {
                ++result;
            }
        }

        return result;
    }
};
