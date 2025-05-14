class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int sumArea = 0;

        int yMax = -1;

       for(int i=0;i<grid.size();i++){
        int xMax = 0;

        for(int j=0;j<grid[i].size();j++){

            // for z
            sumArea += (grid[i][j]>0?1:0);

            xMax = max(xMax,grid[i][j]);
        }
        sumArea += xMax;
       }

        for(int j=0;j<grid[0].size();j++){
            int yMax = 0;
               for(int i=0;i<grid.size();i++){

                 yMax = max(yMax,grid[i][j]);

               }
            sumArea += yMax;

        }
        return sumArea;
    }
};