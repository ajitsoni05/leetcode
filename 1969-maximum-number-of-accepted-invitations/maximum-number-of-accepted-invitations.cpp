class Solution {
public:

    bool dfs(vector<vector<int>>& grid,vector<bool>&visitedGirls,int boy,int& numGirls,vector<int>&matchTo){
        
        for(int girl = 0; girl < numGirls; girl++){

            if(grid[boy][girl] and !visitedGirls[girl]){
                visitedGirls[girl] = true;
                if(matchTo[girl] == -1 || dfs(grid,visitedGirls,matchTo[girl],numGirls,matchTo)){
                    matchTo[girl] = boy;

                    return true;
                }
            }
            
        }
        return false;
    }
    int maximumInvitations(vector<vector<int>>& grid) {
        // dfs | hungarian algo

        if(grid.size() == 0) return 0;

        int numBoys = grid.size();
        int numGirls = grid[0].size();

        // matchTo array 
        vector<int>matchTo(numGirls,-1);


        // dfs call
        int start = 0;

        // result of max match
        int result = 0;

        for(int i = start; i<numBoys;i++){
            // 
            vector<bool>visitedGirl(numGirls,false);

            if(dfs(grid,visitedGirl,i,numGirls,matchTo))result++;
        }

        return result;


    }
};