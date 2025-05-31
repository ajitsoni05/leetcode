class Solution {
public:
    int count(vector<vector<int>>& grid,int i,int j){
        int m = grid.size();
        int n = grid[0].size();

        vector<int> dx = {-1,0,1,0};
        vector<int> dy = {0,1,0,-1};

        int total = 0;

        for(int l = 0; l < 4;l++){
            int x = i + dx[l];
            int y = j + dy[l];

            if(x>=0 and x < m and y>=0 and y < n and grid[x][y]==1)total++;

        }
        return total;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        // let's do simple counting

        int m = grid.size();
        int n = grid[0].size();

        int totalCount = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n;j++){
                if(grid[i][j]==1){
                    totalCount += 4 - count(grid,i,j);
                }
            }
        }
        return totalCount;
    }
};