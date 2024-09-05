class Solution {
public:
    int minDistance(string word1, string word2) {
        

        int n=word1.size(),m=word2.size();
        if(n==0||m==0)return max(n,m);
        vector<vector<int>>dp(word1.size()+1,vector<int>(word2.size()+1,0));

        for(int i=0;i<n;i++){
            dp[n-i][m]=i;
        }
        for(int j=0;j<m;j++){
            dp[n][m-j]=j;
        }

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(word1[i]==word2[j]){
                    dp[i][j]=dp[i+1][j+1];
                }else{
                    dp[i][j]=1+min(dp[i+1][j],min(dp[i][j+1],dp[i+1][j+1]));
                }
            }
        }
        return dp[0][0];
    }
};