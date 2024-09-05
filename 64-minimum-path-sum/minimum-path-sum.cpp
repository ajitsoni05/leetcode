class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>sum(n+1,vector<int>(m+1,INT_MAX));

        sum[n][m-1]=0;

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                sum[i][j]=grid[i][j]+min(sum[i+1][j],sum[i][j+1]);
            }
        }
        


        
        // constructed the sum array

       
       
        return sum[0][0];
    }
};