class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        /*
            lets collect num of fresh oranges
        */
        int fo = 0;
        int m = grid.size(), n = grid[0].size();
        // queue
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)
                    fo++;
                if (grid[i][j] == 2)
                    q.push({i, j});
            }
        }
        if(fo == 0)return 0;
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};
                int mins = 0;

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                pair<int, int> p = q.front();
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int newX = p.first + dx[i];
                    int newY = p.second + dy[i];

                    if (isValid(grid, newX, newY) ) {
                        grid[newX][newY] = 2;
                        fo--;
                        q.push({newX,newY});
                        if (fo == 0)break;

                    }
                }
                
            }
            mins++;
            if(fo == 0)break;
        }
        cout<<fo<<endl;
        return fo?-1:mins;
    }
    bool isValid(vector<vector<int>>& grid, int x, int y) {
        int m = grid.size();
        int n = grid[0].size();

        if (x >= 0 and x < m and y >= 0 and y < n and grid[x][y] == 1)
            return true;
        return false;
    }
};