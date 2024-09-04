class Solution {
public:

    /*

    Recursive approach

    int help(int n){
        if(n==1)return 0;
        else{

            for(int i=1;i<n;i++){
                if(n%i==0){
                    
                    if(help(n-i)==0)return 1;
                }
            }
            return 0;
        }
        
    }

    
    */
    int dp[1001];
    int help(int n){
        if(n==1)return 0;
        if(dp[n]!=-1)return dp[n];
        else{

            for(int i=1;i<n;i++){
                if(n%i==0){
                    
                    if(help(n-i)==0)return dp[n]=1;
                }
            }
            return dp[n]=0;
        }
        
    }
    


    bool divisorGame(int n) {
        // set the memory of dp array
        memset(dp,-1,sizeof(dp));
        return help(n);
    }
};