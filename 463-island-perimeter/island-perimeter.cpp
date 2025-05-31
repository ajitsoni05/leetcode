class Solution {
public:
    bool isValid(vector<vector<int>>&grid,int i,int j){
        int m = grid.size();
        int n = grid[0].size();

        if(i>=0 and i < m and j>=0 and j < n and grid[i][j])return true;
        return false;
    }
    void dfs(vector<vector<int>>&grid, vector<vector<bool>>&vis,int i,int j,int&per){
        vis[i][j] = true;

        int nbCount = 0;

        for(int h = -1; h<=1;h++){
            for(int k = -1; k <=1;k++){
                if(abs(h)!=abs(k) and isValid(grid,i+h,j+k)){
                    nbCount++;
                    if(!vis[i+h][j+k])dfs(grid,vis,i+h,j+k,per);
                }
            }
        }
        per+=4-nbCount;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        
        // check number of neighbours cuz that's important to tell the perimeter

        // we will be doing dfs for this
        // adjacency list

        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>>visited(m,vector<bool>(n,false));

        int per = 0;
        int perimeter = 0;
        for(int i = 0;i< grid.size();i++){
            for(int j = 0; j < grid[i].size();j++){
                if(!visited[i][j] and grid[i][j]){
                    // call dfs
                    dfs(grid,visited,i,j,per);
                }
            }
        }
        return per;

    }
};