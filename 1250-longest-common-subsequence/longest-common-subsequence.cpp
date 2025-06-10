class Solution {
public:
    string s1;
    string s2;
    vector<vector<int>>memo;
    int dp(int iter1,int iter2){
        if(iter1 == s1.size() || iter2 == s2.size())return 0;

        if(memo[iter1][iter2] != -1) return memo[iter1][iter2];
        
        if(s1[iter1] == s2[iter2]){
            memo[iter1][iter2] = 1+ dp(iter1+1,iter2+1);
        }else{
           memo[iter1][iter2] = max(dp(iter1,iter2+1),dp(iter1+1,iter2));
        }

        return memo[iter1][iter2];

        
       
        
    }
    int longestCommonSubsequence(string text1, string text2) {
        // i1 , i2
        s1 = text1;
        s2 = text2;

        memo.resize(s1.size()+1,vector<int>(s2.size()+1,-1));

        return dp(0,0);

    }
};