class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        // get sum of all the grid
        long long totalSum = 0;
        int m = grid.size(), n = grid[0].size();
       
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                totalSum += grid[i][j];
            }
        }

        // check for rows first
        long long rowSum = 0;
        for(int i = 0; i < m; i++){
            // int rowSum = 0;
            for(int j = 0; j < n; j++){
                rowSum += grid[i][j];
            }
            if((totalSum - rowSum) == rowSum)return true;
        }
            
         // check for cols second
        long long colSum = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                colSum += grid[j][i];
            }
            if((totalSum - colSum) == colSum)return true;
        }
        return false;
    }
};