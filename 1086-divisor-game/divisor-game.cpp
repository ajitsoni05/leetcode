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
    /* DP solution (optimized)

    int dp[1001];
    int help(int n){
        if(n==1)return 0;
        if(dp[n]!=-1)return dp[n];
        else{

            for(int i=1;i*i<n;i++){
                if(n%i==0){

                    if(help(n-i)==0)return dp[n]=1;
                    if(i!=1 and help(n-(n/i))==0)return dp[n]=1;
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

    */

    /*
        N= 1 lose
        N=2 win
        N=3 lose
        N=4 win

        N=5 lose


        since factors of odd numbers are always odd, so if alice starts with
       odd, he will make it even to which Bob will further try to make it odd,
       which will eventually result making Alice lose.

    */
    bool divisorGame(int n) { return (n % 2 == 0); }
};