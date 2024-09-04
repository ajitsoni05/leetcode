class Solution {
public:
    int dp[20];
    int catalan_num(int n){
        if(n==0 || n==1)return 1;
        if(dp[n]!=-1)return dp[n];
        int result =0;
        for(int i=0;i<n;i++){
            result+=catalan_num(i)*catalan_num(n-i-1);
        }
        return dp[n]=result;
    }
    int numTrees(int n) {
        // Structurally unique binary search trees
        // having exactly n nodes 
        // This will be done using catalan num concept
        memset(dp,-1,sizeof dp);
        return catalan_num(n);
    }
};