class Solution {
public:
    void dfs(vector<vector<int>>& g,vector<vector<bool>>&vis,int i,int j,bool& open){
        vis[i][j] = true;
        
        int m = g.size();
        int n = g[0].size();

        if(i == m-1 || j == n-1 || i == 0 || j == 0){
            open = true;
        }

        for(int h = -1; h <= 1; h++){
            for(int k = -1; k <= 1; k++){
                if(abs(h)!=abs(k)){
                    if(i+h >= 0 and i+h < m and j+k >=0 and j+k < n and g[h+i][j+k] == 0 and !vis[i+h][j+k]){
                        dfs(g, vis, i+h, j+k, open);
                    }
                }
            }
        }

    }
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // visited matrix
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        
        int count = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){

                if(!visited[i][j] and grid[i][j] == 0){
                    bool open = false;
                    dfs(grid, visited, i, j,open);
                    if(!open) count++;
                }
            }
        }
        
        return count;


    }
};