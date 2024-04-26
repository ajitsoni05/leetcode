class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        // Create a graph using grid 
        // Use Floyd warshall algorithm to get the min dist
        // Traverse the graph and find the distance for i,j
        // for each distance increment the result[dist]++

        // Implement the graph
        vector<vector<int>>grid(n+1,vector<int>(n+1,1000));

        //Also add initial values
        for(int i=1;i<n;i++){
            grid[i][i+1]=1;
            grid[i+1][i]=1;
        }
        grid[x][y]=1;
        grid[y][x]=1;

        // Implement Floyd Warshall Algorithm
        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    grid[i][j]=min(grid[i][j],grid[i][k]+grid[k][j]);
                }
            }
        }

        // Implement the result array
        vector<int>result(n);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i!=j){
                int val=grid[i][j];
                result[val-1]++;
                }

            }
        }
        return result;
    }
};