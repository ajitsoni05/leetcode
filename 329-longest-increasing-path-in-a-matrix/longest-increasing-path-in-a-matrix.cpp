class Solution {
public:
    vector<vector<int>>dp;

    bool isValid(vector<vector<int>>& matrix, int i, int j) {
        int m = matrix.size();
        int n = matrix[0].size();

        if (i >= 0 and i < m and j >= 0 and j < n)
            return true;
        return false;
    }
    int dfs(vector<vector<int>>& matrix, int i, int j) {
        int ans = 0;

        if(dp[i][j]!=-1)return dp[i][j];

        for (int h = -1; h <= 1; h++) {
            for (int k = -1; k <= 1; k++) {
                int nextI = i + h;
                int nextJ = j + k;
                if (abs(h)!=abs(k) and isValid(matrix, nextI, nextJ)  and
                    matrix[nextI][nextJ] > matrix[i][j]) {
                   ans = max(ans, dfs(matrix, nextI, nextJ ));
                }
            }
        }
        return dp[i][j] = ans+1;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        // let's try simple dfs first
        
        int m = matrix.size();
        int  n = matrix[0].size();
        dp.resize(m,vector<int>(n,-1));
        int maxLen = INT_MIN;
        

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                
                int len = dfs(matrix, i, j);
                maxLen = max(maxLen, len);
            }
        }
        return maxLen;

        /*
        
        
            7   8   9
            9   7   6
            7   2   3
        
        */
    }
};