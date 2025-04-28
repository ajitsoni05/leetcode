class Solution {
public:
    bool isValid(vector<vector<char>>& g,vector<vector<bool>>& vis,int x,int y){
        int m = g.size();
        int n = g[0].size();
        if(x>=0 and y>=0 and x<m and y<n and !vis[x][y] and g[x][y]=='1')return true;
        return false;
    }
    void dfs(vector<vector<char>>& g,vector<vector<bool>>& vis,int x,int y){
      vis[x][y]=true;
      for(int i=-1;i<=1;i++){
        for(int j=-1;j<=1;j++){
            if(abs(i)!=abs(j) and isValid(g,vis,x+i,y+j)){
                dfs(g,vis,x+i,y+j);
            }

        }
      }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>>vis(m,vector<bool>(n,false));

        int count =0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] and grid[i][j]=='1'){
                   dfs(grid,vis,i,j);
                   count++; 
                }
            }
        }
        return count;

    }
};